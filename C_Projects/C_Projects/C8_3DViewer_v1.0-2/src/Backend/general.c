#include "general.h"

/* Main parser function */
void parser(FILE *file_ptr, DATAPTR *data_ptr, uint8_t *error) {
  ssize_t read;
  char *line_ptr = NULL;
  size_t len = 0, offset_rows = 1, offset_p = 0;
  checking_and_counting(file_ptr, data_ptr, error, &len);
  if (*error == OK) {
    create_matrix(data_ptr, error);
    create_polygon(data_ptr, error);
    // Возвращаемся к началу файла
    rewind(file_ptr);
    int count_vertex = 1;
    while (!*error && (read = getline(&line_ptr, &len, file_ptr)) != -1) {
      // Парсим вершины
      if (*line_ptr == 'v' && *(line_ptr + 1) == ' ') {
        parser_vertexs(data_ptr, line_ptr, &offset_rows, error);
        count_vertex++;
      }  // Парсим полигоны
      else if (*line_ptr == 'f' && *(line_ptr + 1) == ' ') {
        parser_facets(data_ptr, line_ptr, len, &offset_p, error, &count_vertex);
      }
    }
  }
  free(line_ptr);
  fclose(file_ptr);
}

/* Checking and counting vertexs and polygons in file */
void checking_and_counting(FILE *file_ptr, DATAPTR *data_ptr, uint8_t *error,
                           size_t *len) {
  ssize_t read;
  regmatch_t pmatch;
  char *line_ptr = NULL;
  regex_t regex_v, regex_f;
  int err_comp_regex_v = 1, err_comp_regex_f = 1;
  const char *pattern_vertex_ptr[] = {
      "^v(\\s+-?[0-9]+(\\.([0-9]+)(e-[0-9]+)?)?){3}\\s*(\\s1\\.0)?\\s*$"};
  const char *pattern_polygon_ptr[] = {
      "^f\\s+(-?[0-9]+\\s*|-?[0-9]+\\/[0-9]+\\s*|-?[0-9]+\\/\\/"
      "-?[0-9]+\\s*|(-?[0-9]+\\/){2}-?[0-9]+\\s*){2,}$"};
  /* Функция regcomp предназначена для компиляции рег. выражения */
  err_comp_regex_v = regcomp(&regex_v, *pattern_vertex_ptr, REG_EXTENDED);
  err_comp_regex_f = regcomp(&regex_f, *pattern_polygon_ptr, REG_EXTENDED);
  if (err_comp_regex_v != 0 && err_comp_regex_f != 0) {
    fprintf(stderr, "ERROR: Compliling regex vertex %d.\n", err_comp_regex_v);
    fprintf(stderr, "ERROR: Compliling regex polygon %d.\n", err_comp_regex_f);
    *error = REGEX_COMP_FAIL;
  } else {
    *data_ptr = calloc(1, sizeof(DATA));
    if (data_ptr == NULL) {
      *error = MEMORY_FAIL;
    } else {
      while ((read = getline(&line_ptr, len, file_ptr)) != -1 && *error == OK) {
        if (*line_ptr == 'v' && *(line_ptr + 1) == ' ') {
          (*data_ptr)->count_of_vertexes++;
          if ((err_comp_regex_v = regexec(&regex_v, line_ptr, 1, &pmatch, 0)) !=
              0) {
            *error = VERTEX_IN_FAIL;
          }
        } else if (*line_ptr == 'f' && *(line_ptr + 1) == ' ') {
          (*data_ptr)->count_of_facets++;
          if ((err_comp_regex_f = regexec(&regex_f, line_ptr, 1, &pmatch, 0)) !=
              0) {
            *error = POLYGON_IN_FAIL;
          }
        }
      }
    }
  }
  free(line_ptr);
  regfree(&regex_v);
  regfree(&regex_f);
}

/* Parsing vertexs */
void parser_vertexs(DATAPTR *data_ptr, char *line_ptr, size_t *offset_rows,
                    uint8_t *error) {
  char *c_line_ptr = line_ptr + 2;
  for (int i = 0; i < 3 && !*error; i++, *c_line_ptr++) {
    (*data_ptr)->matrix_3d.matrix[*offset_rows][i] =
        strtod(c_line_ptr, &c_line_ptr);
  }
  (*offset_rows)++;
}

/* Parsing polygons */
void parser_facets(DATAPTR *data_ptr, char *line_ptr, size_t len,
                   size_t *offset_p, uint8_t *error, int *count_vertex) {
  char *c_line_ptr = line_ptr + 2;
  char *dublicate_line_1 = malloc(len * sizeof(char));
  char *dublicate_line_2 = malloc(len * sizeof(char));
  if (dublicate_line_1 == NULL || dublicate_line_2 == NULL) {
    *error = MEMORY_FAIL;
  } else {
    unsigned count_facets = 0;
    strcpy(dublicate_line_1, c_line_ptr);
    strcpy(dublicate_line_2, c_line_ptr);
    char *leksem_line_1 = strtok(dublicate_line_1, " ");
    for (;
         leksem_line_1 != NULL && !is_stop_symbol(leksem_line_1) && !*error;) {
      count_facets++;
      leksem_line_1 = strtok(NULL, " ");
    }
    if (!*error) {
      (*data_ptr)->polygons[*offset_p].number_of_facets = count_facets;
      (*data_ptr)->polygons[*offset_p].vertexes = malloc(
          (*data_ptr)->polygons[*offset_p].number_of_facets * sizeof(int));
      if ((*data_ptr)->polygons[*offset_p].vertexes == NULL) {
        *error = MEMORY_FAIL;
      } else {
        char *leksem_line_2 = strtok(dublicate_line_2, " ");
        for (int i = 0;
             leksem_line_2 != NULL && !is_stop_symbol(leksem_line_2) && !*error;
             i++) {
          int temp = atoi(leksem_line_2);
          if (temp == 0 || abs(temp) >= *count_vertex) {
            *error = FILE_FAIL;
            (*data_ptr)->polygons[*offset_p + 1].vertexes = NULL;
          } else if (temp < 0) {
            temp += *count_vertex;
            (*data_ptr)->polygons[*offset_p].vertexes[i] = temp;
          } else {
            (*data_ptr)->polygons[*offset_p].vertexes[i] = temp;
          }
          leksem_line_2 = strtok(NULL, " ");
        }
      }
    }
    free(dublicate_line_1);
    free(dublicate_line_2);
    (*offset_p)++;
  }
}

/* Memory allocation for polygon */
void create_polygon(DATAPTR *data_ptr, uint8_t *error) {
  if (*error == OK) {
    if ((*data_ptr)->count_of_facets == 0) {
      *error = FILE_FAIL;
    } else {
      (*data_ptr)->polygons =
          malloc((*data_ptr)->count_of_facets * sizeof(polygon_t));
      if ((*data_ptr)->polygons == NULL) {
        *error = MEMORY_FAIL;
      }
    }
  }
}

/* Memory allocation for matrix */
void create_matrix(DATAPTR *data_ptr, uint8_t *error) {
  if ((*data_ptr)->count_of_vertexes == 0) {
    *error = FILE_FAIL;
  } else {
    (*data_ptr)->count_of_vertexes++;
    (*data_ptr)->matrix_3d.rows = (*data_ptr)->count_of_vertexes;
    (*data_ptr)->matrix_3d.columns = 3;
    long double matrix_size = (*data_ptr)->matrix_3d.rows *
                                  (*data_ptr)->matrix_3d.columns *
                                  sizeof(double) +
                              (*data_ptr)->matrix_3d.rows * sizeof(double *);
    (*data_ptr)->matrix_3d.matrix = malloc(matrix_size * sizeof(double));
    if ((*data_ptr)->matrix_3d.matrix == NULL) {
      *error = MEMORY_FAIL;
    } else {
      double *rows_ptr = (double *)((*data_ptr)->matrix_3d.matrix +
                                    (*data_ptr)->matrix_3d.rows);
      for (unsigned i = 0; i < (*data_ptr)->matrix_3d.rows; i++) {
        (*data_ptr)->matrix_3d.matrix[i] =
            rows_ptr + (*data_ptr)->matrix_3d.columns * i;
      }
    }
  }
}

/* Free struct */
void free_struct(DATAPTR *data_ptr) {
  if (*data_ptr) {
    bool flag = 0;
    if ((*data_ptr)->matrix_3d.matrix) {
      free((*data_ptr)->matrix_3d.matrix);
    }
    if ((*data_ptr)->polygons) {
      for (unsigned i = 0; i < (*data_ptr)->count_of_facets && flag == OK;
           i++) {
        if ((*data_ptr)->polygons[i].vertexes) {
          free((*data_ptr)->polygons[i].vertexes);
        } else {
          flag = FAIL;
        }
      }
      free((*data_ptr)->polygons);
    }
    free((*data_ptr));
  }
}

void centering_coordinates(DATAPTR *data_ptr) {
  double min_x = 0, max_x = 0, min_y = 0, max_y = 0, min_z = 0, max_z = 0;
  min_max_cycle_search(data_ptr, X, &min_x, &max_x);
  min_max_cycle_search(data_ptr, Y, &min_y, &max_y);
  min_max_cycle_search(data_ptr, Z, &min_z, &max_z);
  double centr_x = calc_coefficient_centr(&min_x, &max_x);
  double centr_y = calc_coefficient_centr(&min_y, &max_y);
  double centr_z = calc_coefficient_centr(&min_z, &max_z);
  for (unsigned i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    (*data_ptr)->matrix_3d.matrix[i][X] -= centr_x;
    (*data_ptr)->matrix_3d.matrix[i][Y] -= centr_y;
    (*data_ptr)->matrix_3d.matrix[i][Z] -= centr_z;
  }
}

double calc_coefficient_centr(double *min, double *max) {
  return *min + (*max - *min) / 2;
}

/* Func for search max and min number in column */
void min_max_cycle_search(DATAPTR *data_ptr, int column, double *min,
                          double *max) {
  *min = (*data_ptr)->matrix_3d.matrix[1][column];
  *max = (*data_ptr)->matrix_3d.matrix[1][column];
  for (size_t i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    if ((*data_ptr)->matrix_3d.matrix[i][column] > *max) {
      *max = (*data_ptr)->matrix_3d.matrix[i][column];
    } else if ((*data_ptr)->matrix_3d.matrix[i][column] < *min) {
      *min = (*data_ptr)->matrix_3d.matrix[i][column];
    }
  }
}

/* Returns true if char is one of these "\r\n\0" characters */
bool is_stop_symbol(char *ch_ptr) {
  return (*ch_ptr == '\r' || *ch_ptr == '\n' || *ch_ptr == '\0') ? FAIL : OK;
}

/* Calculation of model scale */
void scale_model(DATAPTR *data_ptr, double *scale) {
  double min_x = 0, max_x = 0, min_y = 0, max_y = 0, min_z = 0, max_z = 0;
  min_max_cycle_search(data_ptr, X, &min_x, &max_x);
  min_max_cycle_search(data_ptr, Y, &min_y, &max_y);
  min_max_cycle_search(data_ptr, Z, &min_z, &max_z);
  double max_num = f_max(max_x - min_x, max_y - min_y, max_z - min_z);
  double coefficien_scale = (*scale - (*scale * (-1))) / max_num;
  for (unsigned i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    for (unsigned j = 0; j < (*data_ptr)->matrix_3d.columns; j++) {
      (*data_ptr)->matrix_3d.matrix[i][j] *= coefficien_scale;
    }
  }
}

/* Return max number from three inputs numbers */
double f_max(double x, double y, double z) {
  double result = z;
  if (x >= y && x >= z) {
    result = x;
  } else if (y > x && y > z) {
    result = y;
  }
  return result;
}

void move_model(DATAPTR *data_ptr, double x, double y, double z) {
  move_x(data_ptr, x);
  move_y(data_ptr, y);
  move_z(data_ptr, z);
}

void move_x(DATAPTR *data_ptr, double a) {
  for (unsigned i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    (*data_ptr)->matrix_3d.matrix[i][X] += a;
  }
}

void move_y(DATAPTR *data_ptr, double a) {
  for (unsigned i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    (*data_ptr)->matrix_3d.matrix[i][Y] += a;
  }
}

void move_z(DATAPTR *data_ptr, double a) {
  for (unsigned i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    (*data_ptr)->matrix_3d.matrix[i][Z] += a;
  }
}

void rotate_model(DATAPTR *data_ptr, double x, double y, double z) {
  rotate_x(data_ptr, x);
  rotate_y(data_ptr, y);
  rotate_z(data_ptr, z);
}

void rotate_x(DATAPTR *data_ptr, double angle) {
  for (unsigned i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    double temp_y = (*data_ptr)->matrix_3d.matrix[i][Y];
    double temp_z = (*data_ptr)->matrix_3d.matrix[i][Z];
    (*data_ptr)->matrix_3d.matrix[i][Y] =
        cos(angle) * temp_y - sin(angle) * temp_z;
    (*data_ptr)->matrix_3d.matrix[i][Z] =
        sin(angle) * temp_y + cos(angle) * temp_z;
  }
}

void rotate_y(DATAPTR *data_ptr, double angle) {
  for (unsigned i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    double temp_x = (*data_ptr)->matrix_3d.matrix[i][X];
    double temp_z = (*data_ptr)->matrix_3d.matrix[i][Z];
    (*data_ptr)->matrix_3d.matrix[i][X] =
        cos(angle) * temp_x - sin(angle) * temp_z;
    (*data_ptr)->matrix_3d.matrix[i][Z] =
        sin(angle) * temp_x + cos(angle) * temp_z;
  }
}

void rotate_z(DATAPTR *data_ptr, double angle) {
  for (unsigned i = 1; i < (*data_ptr)->matrix_3d.rows; i++) {
    double temp_x = (*data_ptr)->matrix_3d.matrix[i][X];
    double temp_y = (*data_ptr)->matrix_3d.matrix[i][Y];
    (*data_ptr)->matrix_3d.matrix[i][X] =
        cos(angle) * temp_x - sin(angle) * temp_y;
    (*data_ptr)->matrix_3d.matrix[i][Y] =
        sin(angle) * temp_x + cos(angle) * temp_y;
  }
}