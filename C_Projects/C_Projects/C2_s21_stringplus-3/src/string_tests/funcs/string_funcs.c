/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "unitTests.check" instead.
 */

#include "../s21_string_tests.h"

START_TEST(s21_memchr1) {
  char buffer[20] = "asdmfghjklzxcvbnm";
  int c = 'm';
  int n = 20;
  ck_assert_str_eq(memchr(buffer, c, n), s21_memchr(buffer, c, n));
}
END_TEST

START_TEST(s21_memchr2) {
  char buffer[20] = "asdmfghjklzxcvbnm";
  int c = 'b';
  int n = 10;
  ck_assert_ptr_null(memchr(buffer, c, n));
  ck_assert_ptr_null(s21_memchr(buffer, c, n));
}
END_TEST

START_TEST(s21_memcmp1) {
  char buffer1[20] = "asdfghjklzxcvbnm";
  char buffer2[20] = "asdfghjklzxcvbnm";
  int n = 10;
  ck_assert_int_eq(memcmp(buffer1, buffer2, n),
                   s21_memcmp(buffer1, buffer2, n));
}
END_TEST

START_TEST(s21_memcmp2) {
  char buffer1[20] = "asdfghjklzxcvbnm";
  char buffer2[20] = "asdfghjklzxcvbqm";
  int n = 20;
  ck_assert_int_eq(memcmp(buffer1, buffer2, n),
                   s21_memcmp(buffer1, buffer2, n));
}
END_TEST

START_TEST(s21_memcmp3) {
  char buffer1[20] = "asdfghjklzxcvbzm";
  char buffer2[20] = "asdfghjklzxcvbqm";
  int n = 20;
  ck_assert_int_eq(memcmp(buffer1, buffer2, n),
                   s21_memcmp(buffer1, buffer2, n));
}
END_TEST

START_TEST(s21_memcpy1) {
  char buffer1[20] = "1234567899874566";
  char buffer2[20] = "1234567899874566";
  char source[20] = "asdfghjklzxcvbnm";
  int n = 10;
  memcpy(buffer1, source, n);
  s21_memcpy(buffer2, source, n);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_memcpy2) {
  char buffer1[20] = "1234567899874566";
  char buffer2[20] = "1234567899874566";
  char source[20] = "asdfghjklzxcvbnm";
  int n = 20;
  memcpy(buffer1, source, n);
  s21_memcpy(buffer2, source, n);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_memcpy3) {
  char buffer1[20] = "1234567899874566";
  char buffer2[20] = "1234567899874566";
  char source[20] = "asdfghjklzxcvbnm";
  int n = 0;
  memcpy(buffer1, source, n);
  s21_memcpy(buffer2, source, n);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_memcpy4) {
  char buffer1[20] = "1234567899874566";
  char buffer2[20] = "1234567899874566";
  char source[20] = "asdfghjklzxcvbnm";
  int n = 1;
  memcpy(buffer1, source, n);
  s21_memcpy(buffer2, source, n);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_memset1) {
  char buffer1[20] = "asdfghjklzxcvbnm";
  char buffer2[20] = "asdfghjklzxcvbnm";
  int c = 48;
  int n = 19;
  memset(buffer1, c, n);
  s21_memset(buffer2, c, n);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_memset2) {
  char buffer1[20] = "asdfghjklzxcvbnm";
  char buffer2[20] = "asdfghjklzxcvbnm";
  int c = 49;
  int n = 1;
  memset(buffer1, c, n);
  s21_memset(buffer2, c, n);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_strncat1) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat2) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 13;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat7) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat8) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "My name is Polina.";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat10) {
  char s1[100] = "Hello\0, world!";
  char s2[100] = "Hello\0, world!";
  char s3[] = "My name is\0 Polina.";
  s21_size_t n = 15;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat11) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat12) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat13) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "\0\0\0\0";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat14) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] = "";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strncat15) {
  char s1[100] = "Hello, world!\0\0\0";
  char s2[100] = "Hello, world!\0\0\0";
  char s3[] = "My name is Polina.";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(s1, s3, n), s21_strncat(s2, s3, n));
}
END_TEST

START_TEST(s21_strchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(s21_strncmp1) {
  char buffer1[20] = "asdfghjklzxcvbnm";
  char buffer2[20] = "asdfghjklzxcvbnm";
  int n = 20;
  ck_assert_int_eq(strncmp(buffer1, buffer2, n),
                   s21_strncmp(buffer1, buffer2, n));
}
END_TEST

START_TEST(s21_strncmp2) {
  char buffer1[20] = "asdfghjk\0lzxcvbnm";
  char buffer2[20] = "asdfghjklzxcvbnm";
  int n = 20;
  ck_assert_int_eq(strncmp(buffer1, buffer2, n),
                   s21_strncmp(buffer1, buffer2, n));
}
END_TEST

START_TEST(s21_strncmp3) {
  char buffer1[20] = "asdfghjklzxcvbnm";
  char buffer2[20] = "asdfghjkl\0zxcvbnm";
  int n = 20;
  ck_assert_int_eq(strncmp(buffer1, buffer2, n),
                   s21_strncmp(buffer1, buffer2, n));
}
END_TEST

START_TEST(s21_strncpy1) {
  char buffer1[20] = "123456789987";
  char buffer2[20] = "123456789987";
  char source[20] = "asdfghjkl\000zxcvbnm";
  int n = 11;
  strncpy(buffer1, source, n);
  s21_strncpy(buffer2, source, n);
  ck_assert_str_eq(buffer1, buffer2);
  for (s21_size_t i = 0; i < s21_strlen(buffer1); i++) {
    ck_assert_int_eq(buffer1[i], buffer2[i]);
  }
}
END_TEST

START_TEST(s21_strncpy2) {
  char buffer1[20] = "123456789987";
  char buffer2[20] = "123456789987";
  char source[20] = "asdfghjklzxcvbnm";
  int n = 19;
  strncpy(buffer1, source, n);
  s21_strncpy(buffer2, source, n);
  ck_assert_str_eq(buffer1, buffer2);
  for (s21_size_t i = 0; i < s21_strlen(buffer1); i++) {
    ck_assert_int_eq(buffer1[i], buffer2[i]);
  }
}
END_TEST

START_TEST(s21_strncpy3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "fг-аг-аг";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy4) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy5) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  s21_size_t n = strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strncpy6) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(s21_strcspn1) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn2) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn3) {
  char s1[] = "v";
  char s2[] = "vendetta";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn4) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn6) {
  char s1[] = "6";
  char s2[] = "67";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn9) {
  char s1[] = "699";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn10) {
  char s1[] = "69917020";
  char s2[] = "699";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strcspn12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(s21_strerror1) {
  for (int i = 0; i < 140; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(s21_strlen1) {
  char buffer[20] = "asfghjklzxcvbnm";
  ck_assert_uint_eq(strlen(buffer), s21_strlen(buffer));
}
END_TEST

START_TEST(s21_strlen2) {
  char buffer[20] = "asfghjklzxc\0vbnm";
  ck_assert_uint_eq(strlen(buffer), s21_strlen(buffer));
}
END_TEST

START_TEST(s21_strpbrk1) {
  char buffer[20] = "01234567890cd 5";
  char sym[5] = "5d";
  ck_assert_str_eq(strpbrk(buffer, sym), s21_strpbrk(buffer, sym));
}
END_TEST

START_TEST(s21_strpbrk2) {
  char buffer[20] = "01234567890cd 5";
  char sym[5] = "8947";
  ck_assert_str_eq(strpbrk(buffer, sym), s21_strpbrk(buffer, sym));
}
END_TEST

START_TEST(s21_strpbrk3) {
  char buffer[20] = "01234567890cd 5";
  char sym[5] = "q";
  ck_assert_ptr_null(strpbrk(buffer, sym));
  ck_assert_ptr_null(s21_strpbrk(buffer, sym));
}
END_TEST

START_TEST(s21_strrchr1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(s21_strrchr2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(s21_strrchr3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(s21_strrchr4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(s21_strrchr5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(s21_strrchr6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(s21_strrchr7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(s21_strrchr8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(s21_strstr1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr3) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr4) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "world";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr6) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr7) {
  char s1[] = "";
  char s2[] = "Hello, P!";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr8) {
  char s1[] = "69917020";
  char s2[] = "0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr9) {
  char s1[] = "69917020";
  char s2[] = "\0";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr10) {
  char s1[] = "69917020";
  char s2[] = "32859160 8v3489-74 tvc4y8719c n4[nqymu uv 4vm9cw";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr11) {
  char s1[] = "1   345 345 345 345 345";
  char s2[] = "345";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr12) {
  char s1[] = "sususususpicioussusususpicious";
  char s2[] = "susp";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strstr13) {
  char s1[] = "sus";
  char s2[] = "suspi";
  ck_assert_pstr_eq(strstr(s1, s2), s21_strstr(s1, s2));
}
END_TEST

START_TEST(s21_strtok1) {
  char buffer1[25] = "test1/test2/test3/test4";
  char buffer2[25] = "test1/test2/test3/test4";
  char sep[10] = "/";
  char *test1 = strtok(buffer1, sep);
  char *test2 = s21_strtok(buffer2, sep);
  while (test1 != S21_NULL && test2 != S21_NULL) {
    ck_assert_str_eq(test1, test2);
    test1 = strtok(S21_NULL, sep);
    test2 = s21_strtok(S21_NULL, sep);
  }
}
END_TEST

START_TEST(s21_strtok2) {
  char buffer1[25] = "test1/test2/test3/test4/";
  char buffer2[25] = "test1/test2/test3/test4/";
  char sep[10] = "W";
  char *test1 = strtok(buffer1, sep);
  char *test2 = s21_strtok(buffer2, sep);
  while (test1 != S21_NULL && test2 != S21_NULL) {
    ck_assert_str_eq(test1, test2);
    test1 = strtok(S21_NULL, sep);
    test2 = s21_strtok(S21_NULL, sep);
  }
}
END_TEST

START_TEST(s21_strtok3) {
  char buffer1[25] = "test1/test2/test3/test4/";
  char buffer2[25] = "test1/test2/test3/test4/";
  char sep[10] = "/";
  char *test1 = strtok(buffer1, sep);
  char *test2 = s21_strtok(buffer2, sep);
  while (test1 != S21_NULL && test2 != S21_NULL) {
    ck_assert_str_eq(test1, test2);
    test1 = strtok(S21_NULL, sep);
    test2 = s21_strtok(S21_NULL, sep);
  }
}
END_TEST

START_TEST(s21_to_upper1) {
  char buffer[] = "`abcdefghijklmnopqrstuvwxyz{";
  char *result = s21_to_upper(buffer);
  ck_assert_str_eq("`ABCDEFGHIJKLMNOPQRSTUVWXYZ{", result);
  free(result);
}
END_TEST

START_TEST(s21_to_upper2) {
  char *buffer = S21_NULL;
  char *result = s21_to_upper(buffer);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(s21_to_upper3) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_to_upper4) {
  char buffer[] = "`abcdefg341hijkl mno pqr654!)(_st-*/uvwxyz{";
  char *result = s21_to_upper(buffer);
  ck_assert_str_eq("`ABCDEFG341HIJKL MNO PQR654!)(_ST-*/UVWXYZ{", result);
  free(result);
}
END_TEST

START_TEST(s21_to_lower1) {
  char buffer[] = "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[";
  char *result = s21_to_lower(buffer);
  ck_assert_str_eq("@abcdefghijklmnopqrstuvwxyz[", result);
  free(result);
}
END_TEST

START_TEST(s21_to_lower2) {
  char *buffer = S21_NULL;
  char *result = s21_to_lower(buffer);
  ck_assert_ptr_null(result);
  free(result);
}
END_TEST

START_TEST(s21_to_lower3) {
  char buffer[] = "@ABC324 5435DEF@#$^ &*(GHIJK**+++* //LMNOPQRSTUVWXYZ[";
  char *result = s21_to_lower(buffer);
  ck_assert_str_eq("@abc324 5435def@#$^ &*(ghijk**+++* //lmnopqrstuvwxyz[",
                   result);
  free(result);
}
END_TEST

START_TEST(s21_to_lower4) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = S21_NULL;
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert4) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = S21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert6) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = S21_NULL;
  s21_size_t num = -1;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert9) {
  char s1[] = "wtf";
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_insert10) {
  char s1[] = "";
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim3) {
  char *s1 = S21_NULL;
  char s3[] = "";
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s4 = S21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim9) {
  char s1[] = " wtf ";
  char *s3 = S21_NULL;
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(s21_trim10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

Suite *string_funcs() {
  Suite *suite = suite_create("---string_funcs---");
  TCase *tcase = tcase_create("string_funcs");

  tcase_add_test(tcase, s21_memchr1);
  tcase_add_test(tcase, s21_memchr2);
  tcase_add_test(tcase, s21_memcmp1);
  tcase_add_test(tcase, s21_memcmp2);
  tcase_add_test(tcase, s21_memcmp3);
  tcase_add_test(tcase, s21_memcpy1);
  tcase_add_test(tcase, s21_memcpy2);
  tcase_add_test(tcase, s21_memcpy3);
  tcase_add_test(tcase, s21_memcpy4);
  tcase_add_test(tcase, s21_memset1);
  tcase_add_test(tcase, s21_memset2);
  tcase_add_test(tcase, s21_strncat1);
  tcase_add_test(tcase, s21_strncat2);
  tcase_add_test(tcase, s21_strncat3);
  tcase_add_test(tcase, s21_strncat4);
  tcase_add_test(tcase, s21_strncat5);
  tcase_add_test(tcase, s21_strncat6);
  tcase_add_test(tcase, s21_strncat7);
  tcase_add_test(tcase, s21_strncat8);
  tcase_add_test(tcase, s21_strncat9);
  tcase_add_test(tcase, s21_strncat10);
  tcase_add_test(tcase, s21_strncat11);
  tcase_add_test(tcase, s21_strncat12);
  tcase_add_test(tcase, s21_strncat13);
  tcase_add_test(tcase, s21_strncat14);
  tcase_add_test(tcase, s21_strncat15);
  tcase_add_test(tcase, s21_strchr_1);
  tcase_add_test(tcase, s21_strchr_2);
  tcase_add_test(tcase, s21_strchr_3);
  tcase_add_test(tcase, s21_strchr_4);
  tcase_add_test(tcase, s21_strchr_5);
  tcase_add_test(tcase, s21_strchr_6);
  tcase_add_test(tcase, s21_strchr_7);
  tcase_add_test(tcase, s21_strchr_8);
  tcase_add_test(tcase, s21_strncmp1);
  tcase_add_test(tcase, s21_strncmp2);
  tcase_add_test(tcase, s21_strncmp3);
  tcase_add_test(tcase, s21_strncpy1);
  tcase_add_test(tcase, s21_strncpy2);
  tcase_add_test(tcase, s21_strncpy3);
  tcase_add_test(tcase, s21_strncpy4);
  tcase_add_test(tcase, s21_strncpy5);
  tcase_add_test(tcase, s21_strncpy6);
  tcase_add_test(tcase, s21_strcspn1);
  tcase_add_test(tcase, s21_strcspn2);
  tcase_add_test(tcase, s21_strcspn3);
  tcase_add_test(tcase, s21_strcspn4);
  tcase_add_test(tcase, s21_strcspn5);
  tcase_add_test(tcase, s21_strcspn6);
  tcase_add_test(tcase, s21_strcspn7);
  tcase_add_test(tcase, s21_strcspn8);
  tcase_add_test(tcase, s21_strcspn9);
  tcase_add_test(tcase, s21_strcspn10);
  tcase_add_test(tcase, s21_strcspn11);
  tcase_add_test(tcase, s21_strcspn12);
  tcase_add_test(tcase, s21_strerror1);
  tcase_add_test(tcase, s21_strlen1);
  tcase_add_test(tcase, s21_strlen2);
  tcase_add_test(tcase, s21_strpbrk1);
  tcase_add_test(tcase, s21_strpbrk2);
  tcase_add_test(tcase, s21_strpbrk3);
  tcase_add_test(tcase, s21_strrchr1);
  tcase_add_test(tcase, s21_strrchr2);
  tcase_add_test(tcase, s21_strrchr3);
  tcase_add_test(tcase, s21_strrchr4);
  tcase_add_test(tcase, s21_strrchr5);
  tcase_add_test(tcase, s21_strrchr6);
  tcase_add_test(tcase, s21_strrchr7);
  tcase_add_test(tcase, s21_strrchr8);
  tcase_add_test(tcase, s21_strstr1);
  tcase_add_test(tcase, s21_strstr2);
  tcase_add_test(tcase, s21_strstr3);
  tcase_add_test(tcase, s21_strstr4);
  tcase_add_test(tcase, s21_strstr5);
  tcase_add_test(tcase, s21_strstr6);
  tcase_add_test(tcase, s21_strstr7);
  tcase_add_test(tcase, s21_strstr8);
  tcase_add_test(tcase, s21_strstr9);
  tcase_add_test(tcase, s21_strstr10);
  tcase_add_test(tcase, s21_strstr11);
  tcase_add_test(tcase, s21_strstr12);
  tcase_add_test(tcase, s21_strstr13);
  tcase_add_test(tcase, s21_strtok1);
  tcase_add_test(tcase, s21_strtok2);
  tcase_add_test(tcase, s21_strtok3);
  tcase_add_test(tcase, s21_to_upper1);
  tcase_add_test(tcase, s21_to_upper2);
  tcase_add_test(tcase, s21_to_upper3);
  tcase_add_test(tcase, s21_to_upper4);
  tcase_add_test(tcase, s21_to_lower1);
  tcase_add_test(tcase, s21_to_lower2);
  tcase_add_test(tcase, s21_to_lower3);
  tcase_add_test(tcase, s21_to_lower4);
  tcase_add_test(tcase, s21_insert1);
  tcase_add_test(tcase, s21_insert2);
  tcase_add_test(tcase, s21_insert3);
  tcase_add_test(tcase, s21_insert4);
  tcase_add_test(tcase, s21_insert5);
  tcase_add_test(tcase, s21_insert6);
  tcase_add_test(tcase, s21_insert7);
  tcase_add_test(tcase, s21_insert8);
  tcase_add_test(tcase, s21_insert9);
  tcase_add_test(tcase, s21_insert10);
  tcase_add_test(tcase, s21_trim1);
  tcase_add_test(tcase, s21_trim2);
  tcase_add_test(tcase, s21_trim3);
  tcase_add_test(tcase, s21_trim4);
  tcase_add_test(tcase, s21_trim5);
  tcase_add_test(tcase, s21_trim6);
  tcase_add_test(tcase, s21_trim7);
  tcase_add_test(tcase, s21_trim8);
  tcase_add_test(tcase, s21_trim9);
  tcase_add_test(tcase, s21_trim10);

  suite_add_tcase(suite, tcase);
  return suite;
}