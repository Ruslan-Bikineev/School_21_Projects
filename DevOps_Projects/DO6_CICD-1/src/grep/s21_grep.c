#include "grep.h"

int main(int argc, char *argv[]) {
  if (argc != 1) {
    if (argc < 3) {
      fprintf(stderr,
              "ERROR: Wrong numbers of arguments!\nUsage: ./s21_grep "
              "-[OPTION]...PATTERNS [FILE]...\n");
    } else {
      FLAGS flags = {false, false, false, false, false,       false,
                     false, false, false, false, REG_EXTENDED};
      changeFlags(&flags, argc, argv);
      if (flags.ERROR) {
        fprintf(stderr, "ERROR: Wrong input option %s!\n", argv[1]);
      } else {
        firstTask(flags, argv, argc);
      }
    }
  }
  return 0;
}
