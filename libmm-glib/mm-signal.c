/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details:
 *
 * Copyright (C) 2013-2021 Aleksander Morgado <aleksander@aleksander.es>
 * Copyright (C) 2021 Intel Corporation
 */

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "mm-signal.h"
#include "mm-errors-types.h"

/**
 * SECTION: mm-signal
 * @title: MMSignal
 * @short_description: Helper object to handle extended Signal information.
 *
 * The #MMSignal is an object handling the signal information of the
 * modem.
 */

G_DEFINE_TYPE (MMSignal, mm_signal, G_TYPE_OBJECT)

#define PROPERTY_RSSI        "rssi"
#define PROPERTY_RSCP        "rscp"
#define PROPERTY_ECIO        "ecio"
#define PROPERTY_SINR        "sinr"
#define PROPERTY_IO          "io"
#define PROPERTY_RSRQ        "rsrq"
#define PROPERTY_RSRP        "rsrp"
#define PROPERTY_SNR         "snr"
#define PROPERTY_ERROR_RATE  "error-rate"

struct _MMSignalPrivate {
    gdouble rssi;
    gdouble rscp;
    gdouble ecio;
    gdouble sinr;
    gdouble io;
    gdouble rsrq;
    gdouble rsrp;
    gdouble snr;
    gdouble error_rate;
};

/*****************************************************************************/

/**
 * mm_signal_get_rssi:
 * @self: a #MMSignal.
 *
 * Gets the RSSI (Received Signal Strength Indication), in dBm.
 *
 * Returns: the RSSI, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.2
 */
gdouble
mm_signal_get_rssi (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->rssi;
}

/**
 * mm_signal_set_rssi: (skip)
 */
void
mm_signal_set_rssi (MMSignal *self,
                    gdouble value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->rssi = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_rscp:
 * @self: a #MMSignal.
 *
 * Gets the RSCP (Received Signal Code Power), in dBm.
 *
 * Returns: the RSCP, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.2
 */
gdouble
mm_signal_get_rscp (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->rscp;
}

/**
 * mm_signal_set_rscp: (skip)
 */
void
mm_signal_set_rscp (MMSignal *self,
                    gdouble value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->rscp = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_ecio:
 * @self: a #MMSignal.
 *
 * Gets the Ec/Io, in dB.
 *
 * Only applicable to CDMA1x, CDMA EV-DO and UMTS (WCDMA).
 *
 * Returns: the ECIO, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.2
 */
gdouble
mm_signal_get_ecio (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->ecio;
}

/**
 * mm_signal_set_ecio: (skip)
 */
void
mm_signal_set_ecio (MMSignal *self,
                    gdouble value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->ecio = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_sinr:
 * @self: a #MMSignal.
 *
 * Gets the SINR level, in dB.
 *
 * Only applicable to CDMA EV-DO.
 *
 * Returns: the SINR, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.2
 */
gdouble
mm_signal_get_sinr (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->sinr;
}

/**
 * mm_signal_set_sinr: (skip)
 */
void
mm_signal_set_sinr (MMSignal *self,
                    gdouble value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->sinr = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_io:
 * @self: a #MMSignal.
 *
 * Gets the Io, in dBm.
 *
 * Only applicable to CDMA EV-DO.
 *
 * Returns: the Io, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.2
 */
gdouble
mm_signal_get_io (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->io;
}

/**
 * mm_signal_set_io: (skip)
 */
void
mm_signal_set_io (MMSignal *self,
                    gdouble value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->io = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_rsrp:
 * @self: a #MMSignal.
 *
 * Gets the RSRP (Reference Signal Received Power), in dBm.
 *
 * Only applicable to LTE.
 *
 * Returns: the RSRP, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.2
 */
gdouble
mm_signal_get_rsrp (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->rsrp;
}

/**
 * mm_signal_set_rsrp: (skip)
 */
void
mm_signal_set_rsrp (MMSignal *self,
                    gdouble value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->rsrp = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_rsrq:
 * @self: a #MMSignal.
 *
 * Gets the RSRQ (Reference Signal Received Quality), in dB.
 *
 * Only applicable to LTE.
 *
 * Returns: the RSRQ, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.2
 */
gdouble
mm_signal_get_rsrq (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->rsrq;
}

/**
 * mm_signal_set_rsrq: (skip)
 */
void
mm_signal_set_rsrq (MMSignal *self,
                    gdouble value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->rsrq = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_snr:
 * @self: a #MMSignal.
 *
 * Gets the S/R ration, in dB.
 *
 * Only applicable to LTE.
 *
 * Returns: the S/R ratio, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.2
 */
gdouble
mm_signal_get_snr (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->snr;
}

/**
 * mm_signal_set_snr: (skip)
 */
void
mm_signal_set_snr (MMSignal *self,
                   gdouble value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->snr = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_error_rate:
 * @self: a #MMSignal.
 *
 * Gets the channel error rate (BER, BLER,... depends on the RAT), in
 * percentage.
 *
 * Applicable to all RAT.
 *
 * Returns: the error rate, or %MM_SIGNAL_UNKNOWN if unknown.
 *
 * Since: 1.20
 */
gdouble
mm_signal_get_error_rate (MMSignal *self)
{
    g_return_val_if_fail (MM_IS_SIGNAL (self), MM_SIGNAL_UNKNOWN);

    return self->priv->error_rate;
}

/**
 * mm_signal_set_error_rate: (skip)
 */
void
mm_signal_set_error_rate (MMSignal *self,
                          gdouble   value)
{
    g_return_if_fail (MM_IS_SIGNAL (self));

    self->priv->error_rate = value;
}

/*****************************************************************************/

/**
 * mm_signal_get_dictionary: (skip)
 */
GVariant *
mm_signal_get_dictionary (MMSignal *self)
{
    GVariantBuilder builder;

    /* We do allow NULL */
    if (!self)
        return NULL;

    g_return_val_if_fail (MM_IS_SIGNAL (self), NULL);

    g_variant_builder_init (&builder, G_VARIANT_TYPE ("a{sv}"));

    if (self->priv->rssi != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_RSSI,
                               g_variant_new_double (self->priv->rssi));

    if (self->priv->rscp != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_RSCP,
                               g_variant_new_double (self->priv->rscp));

    if (self->priv->ecio != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_ECIO,
                               g_variant_new_double (self->priv->ecio));

    if (self->priv->sinr != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_SINR,
                               g_variant_new_double (self->priv->sinr));

    if (self->priv->io != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_IO,
                               g_variant_new_double (self->priv->io));

    if (self->priv->rsrp != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_RSRP,
                               g_variant_new_double (self->priv->rsrp));

    if (self->priv->rsrq != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_RSRQ,
                               g_variant_new_double (self->priv->rsrq));

    if (self->priv->snr != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_SNR,
                               g_variant_new_double (self->priv->snr));

    if (self->priv->error_rate != MM_SIGNAL_UNKNOWN)
        g_variant_builder_add (&builder,
                               "{sv}",
                               PROPERTY_ERROR_RATE,
                               g_variant_new_double (self->priv->error_rate));

    return g_variant_ref_sink (g_variant_builder_end (&builder));
}

/*****************************************************************************/

static gboolean
consume_variant (MMSignal *self,
                 const gchar *key,
                 GVariant *value,
                 GError **error)
{
    if (g_str_equal (key, PROPERTY_RSSI))
        self->priv->rssi = g_variant_get_double (value);
    else if (g_str_equal (key, PROPERTY_RSCP))
        self->priv->rscp = g_variant_get_double (value);
    else if (g_str_equal (key, PROPERTY_ECIO))
        self->priv->ecio = g_variant_get_double (value);
    else if (g_str_equal (key, PROPERTY_SINR))
        self->priv->sinr = g_variant_get_double (value);
    else if (g_str_equal (key, PROPERTY_IO))
        self->priv->io = g_variant_get_double (value);
    else if (g_str_equal (key, PROPERTY_RSRP))
        self->priv->rsrp = g_variant_get_double (value);
    else if (g_str_equal (key, PROPERTY_RSRQ))
        self->priv->rsrq = g_variant_get_double (value);
    else if (g_str_equal (key, PROPERTY_SNR))
        self->priv->snr = g_variant_get_double (value);
    else if (g_str_equal (key, PROPERTY_ERROR_RATE))
        self->priv->error_rate = g_variant_get_double (value);
    else {
        /* Set error */
        g_set_error (error,
                     MM_CORE_ERROR,
                     MM_CORE_ERROR_INVALID_ARGS,
                     "Invalid signal dictionary, unexpected key '%s'",
                     key);
        return FALSE;
    }

    return TRUE;
}

/**
 * mm_signal_new_from_dictionary: (skip)
 */
MMSignal *
mm_signal_new_from_dictionary (GVariant *dictionary,
                               GError **error)
{
    GError *inner_error = NULL;
    GVariantIter iter;
    gchar *key;
    GVariant *value;
    MMSignal *self = NULL;

    if (!dictionary) {
        g_set_error (error,
                     MM_CORE_ERROR,
                     MM_CORE_ERROR_INVALID_ARGS,
                     "Cannot create Signal info from empty dictionary");
        return NULL;
    }

    if (!g_variant_is_of_type (dictionary, G_VARIANT_TYPE ("a{sv}"))) {
        g_set_error (error,
                     MM_CORE_ERROR,
                     MM_CORE_ERROR_INVALID_ARGS,
                     "Cannot create Signal info from dictionary: "
                     "invalid variant type received");
        return NULL;
    }

    g_variant_iter_init (&iter, dictionary);
    while (!inner_error && g_variant_iter_next (&iter, "{sv}", &key, &value)) {
        if (!self)
            self = mm_signal_new ();
        consume_variant (self,
                         key,
                         value,
                         &inner_error);
        g_free (key);
        g_variant_unref (value);
    }

    /* If error, destroy the object */
    if (inner_error) {
        g_propagate_error (error, inner_error);
        g_clear_object (&self);
    }

    return self;
}

/*****************************************************************************/

/**
 * mm_signal_new: (skip)
 */
MMSignal *
mm_signal_new (void)
{
    return MM_SIGNAL (g_object_new (MM_TYPE_SIGNAL, NULL));
}

static void
mm_signal_init (MMSignal *self)
{
    self->priv = G_TYPE_INSTANCE_GET_PRIVATE (self, MM_TYPE_SIGNAL, MMSignalPrivate);
    self->priv->rssi = MM_SIGNAL_UNKNOWN;
    self->priv->rscp = MM_SIGNAL_UNKNOWN;
    self->priv->ecio = MM_SIGNAL_UNKNOWN;
    self->priv->sinr = MM_SIGNAL_UNKNOWN;
    self->priv->io   = MM_SIGNAL_UNKNOWN;
    self->priv->rsrq = MM_SIGNAL_UNKNOWN;
    self->priv->rsrp = MM_SIGNAL_UNKNOWN;
    self->priv->snr  = MM_SIGNAL_UNKNOWN;
    self->priv->error_rate = MM_SIGNAL_UNKNOWN;
}

static void
mm_signal_class_init (MMSignalClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS (klass);

    g_type_class_add_private (object_class, sizeof (MMSignalPrivate));
}
