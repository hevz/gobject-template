/*
 ============================================================================
 Name        : hev-iface.h
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.2
 Copyright   : Copyright (C) 2012 everyone.
 Description : 
 ============================================================================
 */

#ifndef __HEV_IFACE_H__
#define __HEV_IFACE_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define HEV_TYPE_IFACE (hev_iface_get_type ())
#define HEV_IFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), HEV_TYPE_IFACE, HevIFace))
#define HEV_IS_IFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HEV_TYPE_IFACE))
#define HEV_IFACE_GET_INTERFACE(inst) (G_TYPE_INSTANCE_GET_INTERFACE ((inst), HEV_TYPE_IFACE, HevIFaceInterface))

typedef struct _HevIFace HevIFace;
typedef struct _HevIFaceInterface HevIFaceInterface;

struct _HevIFaceInterface
{
    GTypeInterface parent_iface;
};

GType hev_iface_get_type (void);

G_END_DECLS

#endif /* __HEV_IFACE_H__ */

