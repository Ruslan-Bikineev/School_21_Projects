#include "tests.h"

int main() {
  // массив test suite с тест кейсами
  Suite *tests[] = {all_tests(), NULL};

  int failed = 0;
  for (int i = 0; tests[i] != NULL; i++) {
    // создаем под каждый suite SRunner и запускаем тесты
    SRunner *sr = srunner_create(tests[i]);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
