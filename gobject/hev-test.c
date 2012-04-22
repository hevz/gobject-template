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

int main(int argc, char *argv[])
{
	GObject *iobj = NULL;

	g_type_init();

	iobj = hev_iobj_new();
	g_return_val_if_fail(G_IS_OBJECT(iobj), -1);
	g_object_unref(iobj);

	return 0;
}
