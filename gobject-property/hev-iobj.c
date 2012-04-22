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
	PROP_ZERO,
	PROP_NAME,
	N_PROPERTIES
};

static GParamSpec * hev_iobj_properties[N_PROPERTIES] = { NULL };

typedef struct _HevIObjPrivate HevIObjPrivate;

struct _HevIObjPrivate
{
	gchar *name;
};

G_DEFINE_TYPE(HevIObj, hev_iobj, G_TYPE_OBJECT);

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

static void hev_iobj_get_property(GObject *obj, guint id,
			GValue *value, GParamSpec *pspec)
{
	HevIObj *self = HEV_IOBJ(obj);
	HevIObjPrivate *priv = HEV_IOBJ_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	switch(id)
	{
	case PROP_NAME:
		g_value_set_string(value, priv->name);
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, id, pspec);
		break;
	}
}

static void hev_iobj_set_property(GObject *obj, guint id,
			const GValue *value, GParamSpec *pspec)
{
	HevIObj *self = HEV_IOBJ(obj);
	HevIObjPrivate *priv = HEV_IOBJ_GET_PRIVATE(self);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	switch(id)
	{
	case PROP_NAME:
		if(priv->name)
		  g_free(priv->name);
		priv->name = g_strdup(g_value_get_string(value));
		break;
	default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, id, pspec);
		break;
	}
}

static void hev_iobj_class_init(HevIObjClass *klass)
{
	GObjectClass *obj_class = G_OBJECT_CLASS(klass);

	g_debug("%s:%d[%s]", __FILE__, __LINE__, __FUNCTION__);

	obj_class->constructor = hev_iobj_constructor;
	obj_class->constructed = hev_iobj_constructed;
	obj_class->dispose = hev_iobj_dispose;
	obj_class->finalize = hev_iobj_finalize;
	obj_class->get_property = hev_iobj_get_property;
	obj_class->set_property = hev_iobj_set_property;

	/* Properties */
	hev_iobj_properties[PROP_NAME] =
		g_param_spec_string("name", "Name", "Name",
					NULL, G_PARAM_READWRITE);
	g_object_class_install_properties(obj_class, N_PROPERTIES,
				hev_iobj_properties);

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

