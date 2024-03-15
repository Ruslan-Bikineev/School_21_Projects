#ifndef CAT_T
#define CAT_T

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  bool b;
  bool e;
  bool n;
  bool s;
  bool t;
  bool v;
  bool ERROR;
} FLAGS;

void changeFlags(FLAGS *flags, int argc, char *argv[]);
void flagV(char);
void printFile(int argc, char *argv[], FLAGS flags);

#endif