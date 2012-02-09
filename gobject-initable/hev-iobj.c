/*
 ============================================================================
 Name        : hev-iobj.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.1
 Copyright   : Copyright (C) 2011 everyone.
 Description : 
 ============================================================================
 */

#include "hev-iobj.h"

#define HEV_IOBJ_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE((obj), HEV_TYPE_IOBJ, HevIObjPrivate))

typedef struct _HevIObjPrivate HevIObjPrivate;

struct _HevIObjPrivate
{
	gchar c;
};

static void hev_iobj_initable_iface_init(GInitableIface * iface);
static gboolean hev_iobj_initable_init(GInitable * initable,
					GCancellable * cancellable, GError ** error);

G_DEFINE_TYPE_WITH_CODE(HevIObj, hev_iobj, G_TYPE_OBJECT,
		G_IMPLEMENT_INTERFACE (G_TYPE_INITABLE, hev_iobj_initable_iface_init));

static void hev_iobj_dispose(GObject * obj)
{
	HevIObj * self = HEV_IOBJ(obj);
	HevIObjPrivate * priv = HEV_IOBJ_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_iobj_parent_class)->dispose(obj);
}

static void hev_iobj_finalize(GObject * obj)
{
	HevIObj * self = HEV_IOBJ(obj);
	HevIObjPrivate * priv = HEV_IOBJ_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_iobj_parent_class)->finalize(obj);
}

static GObject * hev_iobj_constructor(GType type, guint n, GObjectConstructParam * param)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return G_OBJECT_CLASS(hev_iobj_parent_class)->constructor(type, n, param);
}

static void hev_iobj_constructed(GObject * obj)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_iobj_parent_class)->constructed(obj);
}

static void hev_iobj_class_init(HevIObjClass * klass)
{
	GObjectClass * obj_class = G_OBJECT_CLASS(klass);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	obj_class->constructor = hev_iobj_constructor;
	obj_class->constructed = hev_iobj_constructed;
	obj_class->dispose = hev_iobj_dispose;
	obj_class->finalize = hev_iobj_finalize;

	g_type_class_add_private(klass, sizeof(HevIObjPrivate));
}

static void hev_iobj_initable_iface_init(GInitableIface * iface)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	iface->init = hev_iobj_initable_init;
}

static void hev_iobj_init(HevIObj * self)
{
	HevIObjPrivate * priv = HEV_IOBJ_GET_PRIVATE(self);
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

static gboolean hev_iobj_initable_init(GInitable * initable,
					GCancellable * cancellable, GError ** error)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return TRUE;
}

GObject * hev_iobj_new(GCancellable * cancellable, GError ** error)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
	return g_initable_new(HEV_TYPE_IOBJ, cancellable, error, NULL);
}

