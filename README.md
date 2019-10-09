# NixiePixie
NixiePixie Clock in C using Allegro 5 library

## Why

I taught Allegro as part of my [info1 curse](http://info.nachodigital.com.ar/) at the UTN university. [Even had a nice presentation about the whole thing](https://ibonelli.github.io/info1_presentations/Clase15_Juegos_Allegro.html). Things change the lecture is no longer part of info1, but I was left with an interesting program I did and want to share.

All started because I wanted to own a NixiePixie clock, but seemed too expensive to me. So I decided to simulate it.

## Thanks

Mainly to [Victor Conky](https://github.com/GictorBit) who created a [Gnome version](https://www.gnome-look.org/p/1006013/) I used for the graphics. But what he did had Gnome dependencies I didn't like, so decided to re-doit using Allegro library.

## To Compile

First you'll need the Allegro libraries which are easy to install on Debian/Ubuntu:

      sudo apt install liballegro5-dev liballegro5.2 liballegro-image5-dev liballegro-image5.2

This assumes that gcc and its tools have been installed before hand.
Once you have the libraries you can simply compile by running:

      make

## Final thoughts

If you don't like this version or it seems too basic for your needs I later on found [Greg Ercolano version](http://seriss.com/people/erco/unixtools/nixieclock/).

And if you do like it you can contact and tell me at [www.nachodigital.com.ar](http://www.nachodigital.com.ar).
