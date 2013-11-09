/*
 ============================================================================
 Name        : hev-iobj.h
 Author      : Heiher <root@heiher.info>
 Copyright   : Copyright (C) 2013 everyone.
 Description : 
 ============================================================================
 */

#ifndef __HEV_IOBJ_H__
#define __HEV_IOBJ_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define HEV_TYPE_IOBJ (hev_iobj_get_type ())
#define HEV_IOBJ(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
				HEV_TYPE_IOBJ, HevIObj))
#define HEV_IS_IOBJ(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
				HEV_TYPE_IOBJ))
#define HEV_IOBJ_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), \
				HEV_TYPE_IOBJ, HevIObjClass))
#define HEV_IS_IOBJ_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), \
				HEV_TYPE_IOBJ))
#define HEV_IOBJ_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), \
				HEV_TYPE_IOBJ, HevIObjClass))

typedef struct _HevIObj HevIObj;
typedef struct _HevIObjClass HevIObjClass;

struct _HevIObj
{
	GObject parent_instance;
};

struct _HevIObjClass
{
	GObjectClass parent_class;
};

GType hev_iobj_get_type (void);

GObject * hev_iobj_new (void);

G_END_DECLS

#endif /* __HEV_IOBJ_H__ */

