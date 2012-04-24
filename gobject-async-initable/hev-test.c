/*
 ============================================================================
 Name        : hev-test.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.2
 Copyright   : Copyright (c) 2012 everyone.
 Description : 
 ============================================================================
 */

#include "hev-iobj.h"

static void hev_iobj_new_async_handler(GObject *source_object,
			GAsyncResult *res, gpointer user_data)
{
	GObject *iobj = NULL;

	iobj = hev_iobj_new_finish(G_ASYNC_INITABLE(source_object),
				res, NULL);
	if(iobj)
	{
		g_object_unref(iobj);
	}
}

int main(int argc, char *argv[])
{
	g_type_init();

	hev_iobj_new_async(NULL, hev_iobj_new_async_handler,
				NULL);

	return 0;
}
