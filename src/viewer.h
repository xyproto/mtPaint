/*	viewer.h
	Copyright (C) 2004-2016 Mark Tyler and Dmitry Groshev

	This file is part of mtPaint.

	mtPaint is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3 of the License, or
	(at your option) any later version.

	mtPaint is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with mtPaint in the file COPYING.
*/

int font_aa, font_bk, font_r;
int font_bkg, font_angle, font_align;
int font_setdpi, font_dpi, sys_dpi;

extern char *align_txt[];

int view_showing;	// 0: hidden, 1: horizontal split, 2: vertical split
int vw_focus_on;
float vw_zoom;
int opaque_view;
int max_pan;

void **vw_drawing;

void create_cline_area( GtkWidget *vbox1 );

void pressed_pan();

void pressed_centralize(int state);
void pressed_view_focus(int state);
extern void *init_view_code[];		// Initial setup
void view_show();
void view_hide();

int make_text_clipboard(unsigned char *img, int w, int h, int src_bpp);
void pressed_help();
void pressed_text();
void render_text();

void vw_align_size( float new_zoom );				// Set new zoom
void vw_realign();						// Reapply old zoom
void vw_focus_view();						// Focus view window to main window
void vw_focus_idle();						// Same but done in idle cycles
void view_render_rgb( unsigned char *rgb, int px, int py, int pw, int ph, double czoom );
size_t render_layers(unsigned char *rgb, int cxy[4], int pw, int zoom, int scale,
	int lr0, int lr1, int view);
void lr_update_area(int lr, int x, int y, int w, int h);	// Update x,y,w,h area of a layer
#define LR_ANIM 0x10000 /* Update only view window */

int comp_need_alpha(int ftype);					// Need RGBA compositing
void collect_alpha(unsigned char *alpha, int pw, int ph);	// Composite alpha channel

void vw_configure();
