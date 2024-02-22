#include "general.h"

void viewer_3d(char *file_name, uint8_t *error, DATAPTR *data_ptr,
               double *scale) {
  clock_t start, end;
  start = clock();
  double execution_time;
  FILE *file_ptr = fopen(file_name, "r");
  if (file_ptr == NULL) {
    *error = FILE_FAIL;
  } else {
    parser(file_ptr, data_ptr, error);
    if (*error == OK) {
      centering_coordinates(data_ptr);
      scale_model(data_ptr, scale);
    }
  }
  end = clock();
  execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("3D Viewer execution time: %f\n", execution_time);
}