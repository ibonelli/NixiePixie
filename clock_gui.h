#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#include "clock.h"

/*
 * Estructuras para el manejo del reloj
 */

struct digit {
	int value,pos;
	int posx,posy;
};

struct day {
	int dweek;
	int posx,posy;
};

struct digit display[6];

ALLEGRO_BITMAP *numbers=NULL;
int numbers_width,numbers_height;

int clock_gui_init(ALLEGRO_DISPLAY *al_display) {
	ALLEGRO_CONFIG *configfile=NULL;

	numbers=al_load_bitmap("numbers_sprite.png");
	if(!numbers) {
		// Vuelvo y cierro Allegro en la función invocante
		return -1;
	}

	// Inicializo los digitos también
	configfile=al_load_config_file("nixipixie.ini");
	if(!configfile) {
		al_show_native_message_box(al_display, "Error", "Error", "Failed to load configuration file!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	numbers_width=atoi(al_get_config_value(configfile, "DigitWidth", "digitowidth"));
	numbers_height=atoi(al_get_config_value(configfile, "DigitWidth", "digitoheight"));

	display[0].posx=atoi(al_get_config_value(configfile, "BackgroundCoords", "d1xpos"));
	display[0].posy=atoi(al_get_config_value(configfile, "BackgroundCoords", "d1ypos"));

	display[1].posx=atoi(al_get_config_value(configfile, "BackgroundCoords", "d2xpos"));
	display[1].posy=atoi(al_get_config_value(configfile, "BackgroundCoords", "d2ypos"));

	display[2].posx=atoi(al_get_config_value(configfile, "BackgroundCoords", "d3xpos"));
	display[2].posy=atoi(al_get_config_value(configfile, "BackgroundCoords", "d3ypos"));

	display[3].posx=atoi(al_get_config_value(configfile, "BackgroundCoords", "d4xpos"));
	display[3].posy=atoi(al_get_config_value(configfile, "BackgroundCoords", "d4ypos"));

	display[4].posx=atoi(al_get_config_value(configfile, "BackgroundCoords", "d5xpos"));
	display[4].posy=atoi(al_get_config_value(configfile, "BackgroundCoords", "d5ypos"));

	display[5].posx=atoi(al_get_config_value(configfile, "BackgroundCoords", "d6xpos"));
	display[5].posy=atoi(al_get_config_value(configfile, "BackgroundCoords", "d6ypos"));

	//sprintf(msg,"%d",d1x);
	//al_show_native_message_box(display, "Config", "Digit1", msg, NULL, ALLEGRO_MESSAGEBOX_ERROR);

	return 0;
}

void clock_gui_update() {
  int aux;
  get_time();

  aux = get_hour();
  if(aux<24) {
    display[1].value = aux%10;
    display[0].value = (aux-(aux%10))/10;
  } else {
    printf("Wrong time given: %02d", aux);
  }

  aux = get_min();
  if(aux<60) {
    display[3].value = aux%10;
    display[2].value = (aux-(aux%10))/10;
  } else {
    printf("Wrong minutes given: %02d", aux);
  }

  aux = get_sec();
  if(aux<60) {
    display[5].value = aux%10;
    display[4].value = (aux-(aux%10))/10;
  } else {
    printf("Wrong seconds given: %02d", aux);
  }
}

void clock_gui_debug() {
  printf("hh: %d\n", display[5].value);
  printf("hl: %d\n", display[4].value);
  printf("mh: %d\n", display[3].value);
  printf("ml: %d\n", display[2].value);
  printf("sh: %d\n", display[1].value);
  printf("sl: %d\n", display[0].value);
}

void clock_gui_drawdigit(int index) {
	al_draw_bitmap_region(numbers,display[index].value*numbers_width, 0, numbers_width, numbers_height, display[index].posx, display[index].posy, 0);
}

void clock_gui_drawdigits() {
	clock_gui_drawdigit(5);
	clock_gui_drawdigit(4);
	clock_gui_drawdigit(3);
	clock_gui_drawdigit(2);
	clock_gui_drawdigit(1);
	clock_gui_drawdigit(0);
}
