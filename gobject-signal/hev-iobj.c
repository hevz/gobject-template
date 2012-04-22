/*
 ============================================================================
 Name        : hev-iobj.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.2
 Copyright   : Copyright (C) 2012 everyone.
 Description : 
 ============================================================================
 */

#include "hev-iobj.h"

#define HEV_IOBJ_GET_PRIVATE(obj)	(G_TYPE_INSTANCE_GET_PRIVATE((obj), HEV_TYPE_IOBJ, HevIObjPrivate))

enum
{
	SIG_READY,
	LAST_SIGNAL
};

static guint hev_iobj_signals[LAST_SIGNAL] = { 0 };

typedef struct _HevIObjPrivate HevIObjPrivate;

struct _HevIObjPrivate
{
	gchar c;
};

G_DEFINE_TYPE(HevIObj, hev_iobj, G_TYPE_OBJECT);

static void hev_iobj_real_ready(HevIObj *self);

static void hev_iobj_dispose(GObject *obj)
{
	HevIObj *self = HEV_IOBJ(obj);
	HevIObjPrivate *priv = HEV_IOBJ_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_iobj_parent_class)->dispose(obj);
}

static void hev_iobj_finalize(GObject *obj)
{
	HevIObj *self = HEV_IOBJ(obj);
	HevIObjPrivate *priv = HEV_IOBJ_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_iobj_parent_class)->finalize(obj);
}

static GObject * hev_iobj_constructor(GType type, guint n, GObjectConstructParam *param)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	return G_OBJECT_CLASS(hev_iobj_parent_class)->constructor(type, n, param);
}

static void hev_iobj_constructed(GObject *obj)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	G_OBJECT_CLASS(hev_iobj_parent_class)->constructed(obj);

	/* Emit signal */
	g_signal_emit(obj, hev_iobj_signals[SIG_READY], 0);
}

static void hev_iobj_class_init(HevIObjClass *klass)
{
	GObjectClass *obj_class = G_OBJECT_CLASS(klass);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	obj_class->constructor = hev_iobj_constructor;
	obj_class->constructed = hev_iobj_constructed;
	obj_class->dispose = hev_iobj_dispose;
	obj_class->finalize = hev_iobj_finalize;

	klass->ready = hev_iobj_real_ready;

	/* Signals */
	hev_iobj_signals[SIG_READY] = g_signal_new("ready",
				G_TYPE_FROM_CLASS(klass),
				G_SIGNAL_RUN_LAST,
				G_STRUCT_OFFSET(HevIObjClass, ready),
				NULL, NULL,
				g_cclosure_marshal_VOID__VOID,
				G_TYPE_NONE, 0);

	g_type_class_add_private(klass, sizeof(HevIObjPrivate));
}

static void hev_iobj_init(HevIObj *self)
{
	HevIObjPrivate *priv = HEV_IOBJ_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

GObject *hev_iobj_new(void)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	return g_object_new(HEV_TYPE_IOBJ, NULL);
}

static void hev_iobj_real_ready(HevIObj *self)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);
}

