# SPDX-License-Identifier: GPL-2.0-or-later
# Copyright (C) 2021 Iñigo Martinez <inigomartinez@gmail.com>

# helpers library
src_inc = include_directories('.')
kerneldevice_inc = include_directories('kerneldevice')

headers = files(
  'mm-modem-helpers.h',
  'mm-sms-part.h',
)

enums_types = 'mm-helper-enums-types'

enums_sources = []
enums_sources += gnome.mkenums(
  enums_types + '.c',
  sources: headers,
  c_template: build_aux_dir / enums_types + '.c.template',
  fhead: '#include "mm-helper-enums-types.h"',
)

enums_sources += gnome.mkenums(
  enums_types + '.h',
  sources: headers,
  h_template: build_aux_dir / enums_types + '.h.template',
  fhead: '#include "mm-sms-part.h"\n#include "mm-modem-helpers.h"\n#ifndef __MM_HELPER_ENUMS_TYPES_H__\n#define __MM_HELPER_ENUMS_TYPES_H__\n',
  ftail: '#endif /* __MM_HELPER_ENUMS_TYPES_H__ */\n',
)

sources = files(
  'mm-charsets.c',
  'mm-error-helpers.c',
  'mm-log.c',
  'mm-log-object.c',
  'mm-modem-helpers.c',
  'mm-sms-part-3gpp.c',
  'mm-sms-part.c',
  'mm-sms-part-cdma.c',
)

incs = [
  top_inc,
  # FIXME: only necessary if qmi is enabled?
  kerneldevice_inc,
]

deps = [
  libmm_glib_dep,
  mbim_glib_dep,
  qmi_glib_dep,
]

private_deps = []

if enable_qmi
  sources += files('mm-modem-helpers-qmi.c')
endif

if enable_mbim
  sources += files('mm-modem-helpers-mbim.c')
endif

if enable_systemd_journal
  private_deps += libsystemd_dep
endif

libhelpers = static_library(
  'helpers',
  sources: sources + enums_sources,
  include_directories: incs,
  dependencies: deps + private_deps,
)

libhelpers_dep = declare_dependency(
  sources: enums_sources[1],
  include_directories: ['.', kerneldevice_inc],
  dependencies: deps,
  link_with: libhelpers,
)

# kerneldevice library
sources = files(
  'kerneldevice/mm-kernel-device.c',
  'kerneldevice/mm-kernel-device-generic.c',
  'kerneldevice/mm-kernel-device-generic-rules.c',
  'kerneldevice/mm-kernel-device-helpers.c',
)

deps = [
  gudev_dep,
  libhelpers_dep,
  qrtr_glib_dep,
]

if enable_qrtr
  sources += files('kerneldevice/mm-kernel-device-qrtr.c')
endif

if enable_udev
  sources += files('kerneldevice/mm-kernel-device-udev.c')
endif

libkerneldevice = static_library(
  'kerneldevice',
  sources: sources,
  include_directories: top_inc,
  dependencies: deps,
  c_args: '-DUDEVRULESDIR="@0@"'.format(udev_rulesdir),
)

libkerneldevice_dep = declare_dependency(
  dependencies: deps,
  link_with: libkerneldevice,
)

# ports library
headers = files(
  'mm-port.h',
  'mm-port-serial-at.h',
)

sources = files(
  'mm-netlink.c',
  'mm-port.c',
  'mm-port-net.c',
  'mm-port-serial-at.c',
  'mm-port-serial.c',
  'mm-port-serial-gps.c',
  'mm-port-serial-qcdm.c',
  'mm-serial-parsers.c',
)

deps = [libkerneldevice_dep]

private_deps = [gio_unix_dep]

if enable_qmi
  headers += files('mm-port-qmi.h')

  sources += files('mm-port-qmi.c')
endif

if enable_mbim
  sources += files('mm-port-mbim.c')
endif

enums_types = 'mm-port-enums-types'

enums_sources = []
enums_sources += gnome.mkenums(
  enums_types + '.c',
  sources: headers,
  c_template: build_aux_dir / enums_types + '.c.template',
  fhead: '#include "mm-port-enums-types.h"',
)

enums_sources += gnome.mkenums(
  enums_types + '.h',
  sources: headers,
  h_template: build_aux_dir / enums_types + '.h.template',
  fhead: '#include "config.h"\n#include "mm-port.h"\n#include "mm-port-serial-at.h"\n#if defined WITH_QMI\n#include "mm-port-qmi.h"\n#endif\n#ifndef __MM_PORT_ENUMS_TYPES_H__\n#define __MM_PORT_ENUMS_TYPES_H__\n',
  ftail: '#endif /* __MM_PORT_ENUMS_TYPES_H__ */\n',
)

libport = static_library(
  'port',
  sources: sources + enums_sources,
  include_directories: top_inc,
  dependencies: deps + private_deps,
)

libport_dep = declare_dependency(
  sources: enums_sources[1],
  include_directories: '.',
  dependencies: deps,
  link_with: libport,
)

# ModemManager daemon
headers = files(
  'mm-base-bearer.h',
  'mm-filter.h',
  'mm-port-probe.h',
)

sources = files(
  'main.c',
  'mm-auth-provider.c',
  'mm-base-bearer.c',
  'mm-base-call.c',
  'mm-base-manager.c',
  'mm-base-modem-at.c',
  'mm-base-modem.c',
  'mm-base-sim.c',
  'mm-base-sms.c',
  'mm-bearer-list.c',
  'mm-broadband-bearer.c',
  'mm-broadband-modem.c',
  'mm-call-list.c',
  'mm-context.c',
  'mm-device.c',
  'mm-filter.c',
  'mm-iface-modem-3gpp.c',
  'mm-iface-modem-3gpp-profile-manager.c',
  'mm-iface-modem-3gpp-ussd.c',
  'mm-iface-modem.c',
  'mm-iface-modem-cdma.c',
  'mm-iface-modem-firmware.c',
  'mm-iface-modem-location.c',
  'mm-iface-modem-messaging.c',
  'mm-iface-modem-oma.c',
  'mm-iface-modem-sar.c',
  'mm-iface-modem-signal.c',
  'mm-iface-modem-simple.c',
  'mm-iface-modem-time.c',
  'mm-iface-modem-voice.c',
  'mm-plugin.c',
  'mm-plugin-manager.c',
  'mm-port-probe.c',
  'mm-port-probe-at.c',
  'mm-private-boxed-types.c',
  'mm-sms-list.c',
)

enums_types = 'mm-daemon-enums-types'

sources += gnome.mkenums(
  enums_types + '.c',
  sources: headers,
  c_template: build_aux_dir / enums_types + '.c.template',
  fhead: '#include "mm-daemon-enums-types.h"',
)

sources += gnome.mkenums(
  enums_types + '.h',
  sources: headers,
  h_template: build_aux_dir / enums_types + '.h.template',
  fhead: '#include "mm-filter.h"\n#include "mm-base-bearer.h"\n#include "mm-port-probe.h"\n#ifndef __MM_DAEMON_ENUMS_TYPES_H__\n#define __MM_DAEMON_ENUMS_TYPES_H__\n',
  ftail: '#endif /* __MM_DAEMON_ENUMS_TYPES_H__ */\n',
)

deps = [
  gmodule_dep,
  libmm_test_generated_dep,
  libport_dep,
  libqcdm_dep,
]

c_args = [
  '-DMM_COMPILATION',
  '-DPLUGINDIR="@0@"'.format(mm_prefix / mm_pkglibdir),
]

if enable_qrtr
  sources += files('mm-qrtr-bus-watcher.c')
endif

# Additional suspend/resume support via systemd
if enable_systemd_suspend_resume
  sources += files('mm-sleep-monitor.c')

  deps += [
    gio_unix_dep,
    libsystemd_dep,
  ]
endif

if enable_polkit
  deps += polkit_gobject_dep
endif

# Additional QMI support in ModemManager
if enable_qmi
  sources += files(
    'mm-bearer-qmi.c',
    'mm-broadband-modem-qmi.c',
    'mm-call-qmi.c',
    'mm-shared-qmi.c',
    'mm-sim-qmi.c',
    'mm-sms-qmi.c',
  )
endif

# Additional MBIM support in ModemManager
if enable_mbim
  sources += files(
    'mm-bearer-mbim.c',
    'mm-broadband-modem-mbim.c',
    'mm-sim-mbim.c',
    'mm-sms-mbim.c',
  )
endif

executable(
  'ModemManager',
  sources: sources,
  include_directories: top_inc,
  dependencies: deps,
  c_args: c_args,
  install: true,
  install_dir: mm_sbindir,
)

pkg.generate(
  version: mm_version,
  name: mm_name,
  description: 'Common headers provided by ModemManager',
  subdirs: mm_name,
  variables: 'exec_prefix=${prefix}',
)

# generic udev rules
install_data(
  '80-mm-candidate.rules',
  install_dir: udev_rulesdir,
)

subdir('tests')
