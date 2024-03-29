/* hello.c: A program to show the time since the Epoch */

#include <stdio.h>
#include "config.h"

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#else
#include <time.h>
#endif

double get_sec_since_epock()
{
  double sec;

  #ifdef HAVE_GETTIMEOFDAY
    struct timeval tv;

    gettimeofday(&tv, NULL);
    sec = tv.tv_sec;
    sec += tv.tv_usec / 1000000.0;
  #else
    sec = time(NULL);
  #endif

  return sec;
}

int main(int argc, char* argv[]) {
  printf("%f\n", get_sec_since_epock());
  return 0;
}
