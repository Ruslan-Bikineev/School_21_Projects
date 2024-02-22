#ifndef GREP_H
#define GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  bool e;
  bool v;
  bool c;
  bool l;
  bool n;
  bool h;
  bool s;
  bool f;
  bool o;
  bool ERROR;
  int cflags;
} FLAGS;

void changeFlags(FLAGS *flags, int argc, char *argv[]);
void firstTask(FLAGS flags, char *argv[], int argc);
void secondTask(FLAGS flags, FILE *fPtr, regex_t regex, char *argv[],
                int numberFile, int sumFiles);
void firstPrintLine(FLAGS flags, char *argv[], int numberFile, char *linePtr,
                    int sumFiles, int countLine, ssize_t read);
void secondPrintLine(FLAGS flags, char *argv[], int numberFile, int countEqual,
                     int countUnEqual, int sumFiles);
void flagO(FLAGS flags, char *linePtr, regex_t regex, regmatch_t pmatch,
           char *argv[], int numberFile, int countLine, int sumFiles);
char *flagFAndE(int argc, char *argv[]);
bool flagE(char *argv[], char **buffer, int *move, int *i, int *len);
bool flagF(char *argv[], char **buffer, int *move, int *i, int *len);
bool reallocBuffer(int *len, char **buffer);

#endif