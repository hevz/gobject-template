/*
 ============================================================================
 Name        : hev-test.c
 Author      : Heiher <root@heiher.info>
 Copyright   : Copyright (c) 2013 everyone.
 Description : 
 ============================================================================
 */

#include "hev-iobj.h"

static void
hev_iobj_new_async_handler (GObject *source_object,
			GAsyncResult *res,
			gpointer user_data)
{
	GMainLoop *main_loop = user_data;
	HevIObj *iobj = NULL;

	iobj = hev_iobj_new_finish (res, NULL);
	if (iobj)
	{
		g_object_unref (iobj);
		g_main_loop_quit (main_loop);
	}
}

int
main (int argc, char *argv[])
{
	GMainLoop *main_loop = NULL;

	g_type_init ();

	main_loop = g_main_loop_new (NULL, FALSE);

	hev_iobj_new_async (NULL, hev_iobj_new_async_handler,
				main_loop);

	g_main_loop_run (main_loop);

	g_main_loop_unref (main_loop);

	return 0;
}
