# SPDX-License-Identifier: GPL-2.0-or-later
# Copyright (C) 2021 Iñigo Martinez <inigomartinez@gmail.com>

test_units = {
  'at-serial-port': libport_dep,
  'charsets': libhelpers_dep,
  'error-helpers': libhelpers_dep,
  'modem-helpers': libhelpers_dep,
  'sms-part-3gpp': libhelpers_dep,
  'sms-part-cdma': libhelpers_dep,
  'udev-rules': libkerneldevice_dep,
}

deps = [
  libport_dep,
  libqcdm_dep,
  util_dep,
]

test_units += {'qcdm-serial-port': deps}

if enable_qmi
  test_units += {'modem-helpers-qmi': libkerneldevice_dep}
endif

foreach test_unit, test_deps: test_units
  test_name = 'test-' + test_unit

  exe = executable(
    test_name,
    sources: test_name + '.c',
    include_directories: top_inc,
    dependencies: test_deps,
    c_args: '-DTESTUDEVRULESDIR="@0@"'.format(src_dir)
  )

  test(test_name, exe)
endforeach
