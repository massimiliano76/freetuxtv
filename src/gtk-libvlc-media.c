/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8-*- */
/*
 * freetuxtv
 * Copyright (C) FreetuxTV Team's 2008
 * Project homepage : http://code.google.com/p/freetuxtv/
 * 
 * freetuxtv is free software.
 * 
 */

#include "gtk-libvlc-media.h"

static void
gtk_libvlc_media_class_init(GtkLibVLCMediaClass *klass);
static void
gtk_libvlc_media_init(GtkLibVLCMedia *object);
static void
gtk_libvlc_media_dispose(GObject *object);
static void
gtk_libvlc_media_finalize(GObject *object);

G_DEFINE_TYPE (GtkLibVLCMedia, gtk_libvlc_media, G_TYPE_OBJECT);

/**
 * gtk_libvlc_media_new:
 * @mrl: the MRL (media resource locator) of the media.
 *
 * Create a new media to be played in a #GtkLibVLCMediaPlayer with the given mrl.
 *
 * Returns: a media. Should be freed when it is no longer needed with g_object_unref().
 *
 * Since: 0.1
 */
GtkLibVLCMedia*
gtk_libvlc_media_new (gchar* mrl)
{
	g_return_if_fail(mrl != NULL);

	GtkLibVLCMedia *self = NULL;
	self = g_object_new (GTK_TYPE_LIBVLC_MEDIA, NULL);

	self->mrl = g_strdup(mrl);
	
	return self;
}

static void
gtk_libvlc_media_class_init (GtkLibVLCMediaClass *klass)
{
	GObjectClass *object_class;
	
	object_class = G_OBJECT_CLASS (klass);
	
	object_class->dispose = gtk_libvlc_media_dispose;
	object_class->finalize = gtk_libvlc_media_finalize;
}

static void
gtk_libvlc_media_init (GtkLibVLCMedia *object)
{
	object->mrl = NULL;
}

static void
gtk_libvlc_media_dispose(GObject *object)
{
	 GtkLibVLCMedia *self;
	 g_return_if_fail(object != NULL);
	 g_return_if_fail(GTK_IS_LIBVLC_MEDIA(object));	 
	 
	 self = GTK_LIBVLC_MEDIA(object);

	 if(self->mrl != NULL){
		 g_free(self->mrl);
		 self->mrl = NULL;
	 }
	 
	 G_OBJECT_CLASS (gtk_libvlc_media_parent_class)->dispose (object);
}

static void
gtk_libvlc_media_finalize(GObject *object)
{
	 GtkLibVLCMedia *self;
	 g_return_if_fail(object != NULL);
	 g_return_if_fail(GTK_IS_LIBVLC_MEDIA(object));	 
	 
	 self = GTK_LIBVLC_MEDIA(object);

	 G_OBJECT_CLASS (gtk_libvlc_media_parent_class)->finalize (object);
}
