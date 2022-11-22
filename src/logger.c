#include <stdio.h>
#include "logger.h"


void Logger__int(int n) {
  char str[10];
  FILE *f;
  sprintf(str, "%d", n);
  f = fopen("x.log", "a+");
  if (f == NULL) { /* Something is wrong   */}
  fprintf(f, "%s", str);
  fclose(f);
}

void Logger__str(char * message) {
  FILE *f;
  f = fopen("x.log", "a+");
  if (f == NULL) { /* Something is wrong   */}
  fprintf(f, "%s", message);
  fclose(f);
}
