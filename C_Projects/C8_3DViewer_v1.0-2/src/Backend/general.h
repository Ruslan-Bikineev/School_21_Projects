#ifndef GENERAL_H
#define GENERAL_H
#include <ctype.h>
#include <math.h>
#include <regex.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*----------------------------MACROS----------------------------*/
#define OK 0
#define FAIL 1
#define MEMORY_FAIL 2      // if calloc or malloc return null
#define FILE_FAIL 3        // if .obj file have incorrect symbols
#define REGEX_COMP_FAIL 4  // if regex compilation fail
#define VERTEX_IN_FAIL 5   // if vertexs parsing fail
#define POLYGON_IN_FAIL 6  // if pologyns parsing fail

#define X 0
#define Y 1
#define Z 2

// colors
#define R 0
#define G 1
#define B 2

// type projection
#define CENTRAL 1
#define ORTHOGONAL 2

// type lines
#define SOLID 0
#define DASHED 1

// type vertexes
#define NONE 0
#define CIRCLE 1
#define SQUARE 2

/*--------------------------------DATA---------------------------------*/
typedef struct matrix_struct {
  double **matrix;
  unsigned rows;
  unsigned columns;
} matrix_t;

typedef struct facets {
  int *vertexes;
  int number_of_facets;
} polygon_t;

typedef struct data {
  unsigned count_of_vertexes;
  unsigned count_of_facets;
  matrix_t matrix_3d;
  polygon_t *polygons;
} DATA;

typedef DATA *DATAPTR;

/*----------------------------GENERAL----------------------------*/
void free_struct(DATAPTR *);
void create_matrix(DATAPTR *, uint8_t *);
void create_polygon(DATAPTR *, uint8_t *);
void parser(FILE *, DATAPTR *, uint8_t *);
void viewer_3d(char *, uint8_t *, DATAPTR *, double *);
void parser_vertexs(DATAPTR *, char *, size_t *, uint8_t *);
void checking_and_counting(FILE *, DATAPTR *, uint8_t *, size_t *);
void parser_facets(DATAPTR *, char *, size_t, size_t *, uint8_t *, int *);

bool is_stop_symbol(char *);
double f_max(double, double, double);
void scale_model(DATAPTR *, double *);
void centering_coordinates(DATAPTR *);
double calc_coefficient_centr(double *, double *);
void min_max_cycle_search(DATAPTR *, int, double *, double *);

void move_x(DATAPTR *, double);
void move_y(DATAPTR *, double);
void move_z(DATAPTR *, double);
void move_model(DATAPTR *, double, double, double);

void rotate_x(DATAPTR *, double);
void rotate_y(DATAPTR *, double);
void rotate_z(DATAPTR *, double);
void rotate_model(DATAPTR *, double, double, double);

#endif
