/*
 ============================================================================
 Name        : hev-test.c
 Author      : Heiher <root@heiher.info>
 Copyright   : Copyright (c) 2013 everyone.
 Description : 
 ============================================================================
 */

#include "hev-iobj.h"

int
main (int argc, char *argv[])
{
	GObject *iobj = NULL;

#ifndef GLIB_VERSION_2_36
	g_type_init ();
#endif

	iobj = hev_iobj_new ();
	g_return_val_if_fail (G_IS_OBJECT (iobj), -1);
	g_object_unref (iobj);

	return 0;
}
