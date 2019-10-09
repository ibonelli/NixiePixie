#include <time.h>
#include <stdio.h>

/*
 * Estructuras para el manejo del reloj
 */

struct clock_time {
	int hour,min,sec;
};

struct clock_day {
	int daymonth,dweek,month,year;
};

time_t time_epoch;
struct tm human_time;

void get_time() {
  time_epoch = time(&time_epoch);
  localtime_r(&time_epoch, &human_time);
  //printf("%02d:%02d:%02d\n",human_time.tm_hour,human_time.tm_min,human_time.tm_sec);
}

int get_hour() {
  return human_time.tm_hour;
}

int get_min() {
  return human_time.tm_min;
}

int get_sec() {
  return human_time.tm_sec;
}
