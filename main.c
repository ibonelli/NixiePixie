/*
 *  NixiPixie Clock
 *  Copyright (C) 2016 Ignacio Bonelli, ignacio@nachodigital.com.ar
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#include "clock_gui.h"

/*
 * Para la hora usar ctime
 */

const float FPS=60;

int main(int argc, char **argv){

	ALLEGRO_DISPLAY *display=NULL;
	ALLEGRO_EVENT_QUEUE *event_queue=NULL;
	ALLEGRO_TIMER *timer=NULL;

	ALLEGRO_BITMAP *background=NULL;
	ALLEGRO_BITMAP *dayweek=NULL;

	bool redraw=true;
	int i=0;
	//char msg[50];

	if(!al_init()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if(!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_background_addon!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	timer=al_create_timer(1.0 / FPS);
	if(!timer) {
		al_show_native_message_box(display, "Error", "Error", "failed to create timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	display=al_create_display(465, 130);
	if(!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_timer(timer);
		return -1;
	}

	event_queue=al_create_event_queue();
	if(!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
	al_start_timer(timer);

	background=al_load_bitmap("background.png");
	if(!background) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load background!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_event_queue(event_queue);
		return -1;
	}

	if(clock_gui_init(display) == -1) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load background!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_event_queue(event_queue);
		return -1;
	}

	dayweek=al_load_bitmap("dayweek_sprite.png");
	if(!dayweek) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load background!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_event_queue(event_queue);
		return -1;
	}

	al_draw_bitmap(background,0,0,0);
	al_flip_display();
	al_rest(1);

	while(1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
 
		if(ev.type == ALLEGRO_EVENT_TIMER) {
			if(i<25)
				i++;
			else {
				i=0;
				redraw=true;
				clock_gui_update();
				clock_gui_drawdigits();
			}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
 
		if(redraw && al_is_event_queue_empty(event_queue)) {
			if(redraw)
			redraw=false;
			al_flip_display();
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
