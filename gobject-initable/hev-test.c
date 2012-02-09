/*
 ============================================================================
 Name        : hev-test.c
 Author      : Heiher <admin@heiher.info>
 Version     : 0.0.1
 Copyright   : Copyright (c) 2010 everyone.
 Description : 
 ============================================================================
 */

#include "hev-iobj.h"

int main(int argc, char * argv[])
{
	GObject * iobj = NULL;

	g_type_init();

	iobj = hev_iobj_new(NULL, NULL);
	g_return_val_if_fail(G_IS_OBJECT(iobj), -1);
	g_object_unref(iobj);

	return 0;
}
