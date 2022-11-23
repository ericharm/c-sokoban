#include <stdio.h>
#include "logger.h"


void log_int(int n) {
  char str[10];
  FILE *f;
  sprintf(str, "%d", n);
  f = fopen("log.txt", "a+");
  if (f == NULL) { /* Something is wrong   */}
  fprintf(f, "%s", str);
  fclose(f);
}

void log_str(char * message) {
  FILE *f;
  f = fopen("log.txt", "a+");
  if (f == NULL) { /* Something is wrong   */}
  fprintf(f, "%s", message);
  fclose(f);
}
