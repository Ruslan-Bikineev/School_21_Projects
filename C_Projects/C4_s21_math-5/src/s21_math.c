#include "s21_math.h"

/*|1|Вычисляет абсолютное значение целого числа*/
int s21_abs(int x) { return (x > 0) ? x : -x; }

/*|2|Вычисляет обратный косинус*/
long double s21_acos(double x) {
  long double res;
  if (x < S21_LDMAX && x > S21_LDMIN) {
    res = S21_PI / 2 - s21_asin(x);
  } else {
    res = S21_NAN;
  }
  return res;
}

/*|3|Вычисляет обратный синус*/
long double s21_asin(double x) {
  if (x < S21_LDMAX && x > S21_LDMIN) {
    long double sum = x;
    if (s21_fabs(x) > 1) {
      sum = S21_NAN;
    } else if (s21_fabs(x) == 1) {
      sum = S21_PI / 2 * x;
    } else {
      long double mem = x;
      int n = 1;
      while (s21_fabs(mem) > S21_E) {
        mem = mem * x * x * (2 * n - 1) * (2 * n - 1) / ((2 * n + 1) * 2 * n);
        sum += mem;
        n += 1;
      }
    }
    return sum;
  } else {
    return S21_NAN;
  }
}

/*|4|Вычисляет обратный тангенс*/
long double s21_atan(double x) {
  long double res;
  if (x < S21_LDMAX && x > S21_LDMIN) {
    res = s21_asin(x / s21_sqrt(1 + x * x));
  } else {
    res = S21_NAN;
  }
  return res;
}

/*|5|Возвращает ближайшее целое число, не меньшее заданного значения*/
long double s21_ceil(double x) {
  long double result = (long long int)x;
  if (x > S21_LDMAX) {
    result = S21_POSINF;
  } else if (x < S21_LDMIN) {
    result = S21_NEGINF;
  } else if (x != x) {
    result = S21_NAN;
  } else {
    if (x > 0.0 && x != result) {
      result += 1.0;
    }
  }
  return result;
}

/*|6|Вычисляет косинус*/
long double s21_cos(double x) {
  long double sum = 1;
  if (x < S21_LDMAX && x > S21_LDMIN) {
    x = (double)s21_fmod(x, 2 * S21_PI);
    if (s21_fabs(x) > S21_PI) {
      x -= 2 * S21_PI;
    }
    double mem = 1;

    int n = 2;
    while (s21_fabs(mem) > S21_E) {
      mem = -mem;
      mem = (mem * x * x / (n * (n - 1)));
      sum += mem;
      n += 2;
    }
  } else {
    sum = S21_NAN;
  }
  return sum;
}

/*|7|Возвращает значение e, возведенное в заданную степень*/
long double s21_exp(double x) {
  bool flag = true;
  long double result = 1.0;
  if (x != x) {
    result = S21_NAN;
  } else {
    if (x > S21_LDMAX) {
      result = S21_POSINF;
    } else if (x <= -25) {
      result = -0.0;
    } else {
      /* цикл работает до точночти 1-е10, либо пока результат не вышел за
      диапазон максимума LD, начинаются расхождения в тысячных после степени
      30*/
      for (long double count = 1.0, value = 1.0;
           flag && s21_fabs(value) > S21_E; count++) {
        value *= (long double)x / count;
        result += value;
        if (result > S21_LDMAX) {
          result = S21_POSINF;
          flag = false;
        }
      }
    }
  }
  return s21_fabs(result);
}

/*|8|Вычисляет абсолютное значение числа с плавающей точкой*/
long double s21_fabs(double x) {
  return (x > 0.0) ? (long double)x : (long double)-x;
}

/*|9|Возвращает ближайшее целое число, не превышающее заданное значение*/
long double s21_floor(double x) {
  long double result = (long long int)x;
  if (x > S21_LDMAX) {
    result = S21_POSINF;
  } else if (x < S21_LDMIN) {
    result = S21_NEGINF;
  } else if (x != x) {
    result = S21_NAN;
  } else {
    if (x < 0.0 && x != result) {
      result -= 1.0;
    }
  }
  return result;
}

/*|10|Остаток операции деления с плавающей точкой*/
long double s21_fmod(double x, double y) {
  long double result = 0.0;
  if (y > S21_LDMAX || y < S21_LDMIN) {
    result = (long double)x;
  } else if (y == 0.0 || x > S21_LDMAX || x < S21_LDMIN || x != x) {
    result = -S21_NAN;
  } else {
    long long int i = 0;
    i = x / y;
    result = (long double)x - (i * (long double)y);
  }
  return result;
}

/*|11|Вычисляет натуральный логарифм
 Реализация итерационным методом Галлея*/
long double s21_log(double x) {
  long double result = 0.0, pow = 0.0;
  if (x > S21_LDMAX) {
    result = S21_POSINF;
  } else if (x == 0.0) {
    result = S21_NEGINF;
  } else if (x < 0.0) {
    result = S21_NAN;
  } else {
    for (; x >= S21_EULER; x /= S21_EULER, pow++)
      ;
    long double yN = 0.0;
    for (int i = 0; i < 100; i++) {
      result = yN + 2 * (x - s21_exp(yN)) / (x + s21_exp(yN));
      yN = result;
    }
  }
  return result + pow;
}

/*|12|Возводит число в заданную степень*/
long double s21_pow(double base, double exp) {
  bool flag = false;
  long long int round = exp;
  long double result = 0.0;
  if (base < 0.0 && round != exp) {
    result = -S21_NAN;
  } else if (base == 0.0 && exp == 0.0) {
    result = 1.0;
  } else if (base == 0.0 && exp > 0.0) {
    result = 0.0;
  } else if (base == 0 && exp < 0.0) {
    result = S21_POSINF;
  } else {
    if (base < 0.0) {
      base = s21_fabs(base);
      flag = (s21_fmod(exp, 2) != 0.0) ? true : false;
    }
    result = s21_exp(exp * s21_log(s21_fabs(base)));
    if (round == exp) {
      result = s21_floor(result);
    }
  }
  return flag ? -result : result;
}

/*|13|Вычисляет синус*/
long double s21_sin(double x) {
  long double res = 0;
  if (x < S21_LDMAX && x > S21_LDMIN) {
    x = (double)s21_fmod(x, 2 * S21_PI);
    if (x > S21_PI) {
      x -= 2 * S21_PI;
    } else if (x < S21_PI) {
      x += 2 * S21_PI;
    }
    double mem = x;
    long double sum = x;
    int n = 3;
    while (s21_fabs(mem) > S21_E) {
      mem = -mem;
      mem = (mem * x * x / (n * (n - 1)));
      sum += mem;
      n += 2;
    }
    res = sum;
  } else {
    res = S21_NAN;
  }
  return res;
}

/*|14|Вычисляет квадратный корень
Реализовано методом половинного деления*/
long double s21_sqrt(double x) {
  long double result = 0.0;
  if (x < 0.0) {
    result = -S21_NAN;
  } else {
    long double leftX = 0.0, rightX = 0.0;
    rightX = x < 1.0 ? 1 : x;
    result = (leftX + rightX) / 2;
    while ((result - leftX) > S21_E) {
      if (result * result > x) {
        rightX = result;
      } else {
        leftX = result;
      }
      result = (leftX + rightX) / 2;
    }
  }
  return result;
}

/*|15|Вычисляет тангенс*/
long double s21_tan(double x) {
  long double res = 0;
  if (x < S21_LDMAX && x > S21_LDMIN) {
    res = s21_sin(x) / s21_cos(x);
  } else {
    res = S21_NAN;
  }
  return res;
}