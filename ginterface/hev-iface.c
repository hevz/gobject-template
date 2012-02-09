/*
 ============================================================================
 Name        : hev-iface.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.1
 Copyright   : Copyright (C) 2011 everyone.
 Description : 
 ============================================================================
 */

#include "hev-iface.h"

G_DEFINE_INTERFACE(HevIFace, hev_iface, G_TYPE_OBJECT);

static void hev_iface_default_init(HevIFaceInterface * klass)
{
}

