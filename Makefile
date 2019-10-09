#
#  Makefile
#  Ejemplos de: 
#      http://fixbyproximity.com/2011/10/18/2d-game-dev-part-9-3-revisiting-our-game-the-explosions/
#

LIBS = -lallegro -lallegro_main -lallegro_image -lallegro_audio -lallegro_acodec -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_dialog
CFLAGS = -Wall

all: nixipixieclock

nixipixieclock: main.c
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm nixipixieclock
