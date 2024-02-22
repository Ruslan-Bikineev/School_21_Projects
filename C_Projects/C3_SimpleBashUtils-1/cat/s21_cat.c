#include "cat.h"

int main(int argc, char *argv[]) {
  if (argc != 1) {
    FLAGS flags = {false};
    changeFlags(&flags, argc, argv);
    if (!flags.e && !flags.b && !flags.ERROR && !flags.n && !flags.s &&
        !flags.s && !flags.t && !flags.v) {
      for (int i = 1; i < argc; i++) {
        FILE *fPtr = fopen(argv[i], "r");
        if (fPtr == NULL) {
          fprintf(stderr, "ERROR: File %s could not be found!\n", argv[i]);
        } else {
          char ch;
          while ((ch = fgetc(fPtr)) != EOF) {
            printf("%c", ch);
          }
          fclose(fPtr);
        }
      }
    } else {
      if (!flags.ERROR) {
        printFile(argc, argv, flags);
      } else {
        fprintf(stderr, "ERROR: %s Incorrect input option!\n", argv[1]);
      }
    }
  }
  return 0;
}
