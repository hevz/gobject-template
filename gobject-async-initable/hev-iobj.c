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
	STEP_ZERO,
	STEP_FIRST,
	STEP_SECOND,
	N_STEPS
};

typedef struct _HevIObjPrivate HevIObjPrivate;

struct _HevIObjPrivate
{
	gint step;
};

static void hev_iobj_async_initable_iface_init(GAsyncInitableIface *iface);
static void hev_iobj_async_initable_init_async(GAsyncInitable *initable,
			gint io_priority, GCancellable *cancellable,
			GAsyncReadyCallback callback, gpointer user_data);
static gboolean hev_iobj_async_initable_init_finish(GAsyncInitable *initable,
			GAsyncResult *result, GError **error);

G_DEFINE_TYPE_WITH_CODE(HevIObj, hev_iobj, G_TYPE_OBJECT,
		G_IMPLEMENT_INTERFACE(G_TYPE_ASYNC_INITABLE, hev_iobj_async_initable_iface_init));

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
}

static void hev_iobj_class_init(HevIObjClass *klass)
{
	GObjectClass *obj_class = G_OBJECT_CLASS(klass);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	obj_class->constructor = hev_iobj_constructor;
	obj_class->constructed = hev_iobj_constructed;
	obj_class->dispose = hev_iobj_dispose;
	obj_class->finalize = hev_iobj_finalize;

	g_type_class_add_private(klass, sizeof(HevIObjPrivate));
}

static void hev_iobj_async_initable_iface_init(GAsyncInitableIface *iface)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	iface->init_async = hev_iobj_async_initable_init_async;
	iface->init_finish = hev_iobj_async_initable_init_finish;
}

static void hev_iobj_init(HevIObj *self)
{
	HevIObjPrivate *priv = HEV_IOBJ_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	priv->step = STEP_ZERO;
}

static void hev_iobj_async_initable_init_async(GAsyncInitable *initable,
			gint io_priority, GCancellable *cancellable,
			GAsyncReadyCallback callback, gpointer user_data)
{
	HevIObj *self = HEV_IOBJ(initable);
	HevIObjPrivate *priv = HEV_IOBJ_GET_PRIVATE(self);
	GSimpleAsyncResult *simple = NULL;

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	simple = g_simple_async_result_new(G_OBJECT(initable),
				callback, user_data, hev_iobj_async_initable_init_async);

	switch(priv->step)
	{
	case STEP_ZERO:
		g_debug("%s:%d[%s]=>(%s)", __FILE__, __LINE__,
					__FUNCTION__, "Zero");
		priv->step = STEP_FIRST;
	case STEP_FIRST:
		g_debug("%s:%d[%s]=>(%s)", __FILE__, __LINE__,
					__FUNCTION__, "Frist");
		priv->step = STEP_SECOND;
	case STEP_SECOND:
		g_debug("%s:%d[%s]=>(%s)", __FILE__, __LINE__,
					__FUNCTION__, "Second");
		g_simple_async_result_set_check_cancellable(simple, cancellable);
		g_simple_async_result_complete(simple);
		g_object_unref(simple);
		break;
	}
}

static gboolean hev_iobj_async_initable_init_finish(GAsyncInitable *initable,
			GAsyncResult *result, GError **error)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	g_return_val_if_fail(g_simple_async_result_is_valid(result,
					G_OBJECT(initable), hev_iobj_async_initable_init_async),
				FALSE);
	if(g_simple_async_result_propagate_error(G_SIMPLE_ASYNC_RESULT(result),
					error))
	  return FALSE;

	return TRUE;
}

void hev_iobj_new_async(GCancellable *cancellable,
			GAsyncReadyCallback callback, gpointer user_data)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	g_async_initable_new_async(HEV_TYPE_IOBJ, G_PRIORITY_DEFAULT,
				cancellable, callback, user_data, NULL);
}

GObject * hev_iobj_new_finish(GAsyncInitable *initable,
			GAsyncResult *res, GError **error)
{
	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	return g_async_initable_new_finish(initable, res, error);
}
