#include "s21_matrix_oop.h"

#include <cmath>
#include <iostream>

/*----------------------------------------------------------------------------*/
/* Based constructor, initialized matrix 1x1 */
S21Matrix::S21Matrix() : S21Matrix(1, 1) {}

/* Contructor with numbers of rows and cols */
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  matrix_ = new double *[rows_ * cols_ + rows_]();
  double *ptr = (double *)(matrix_ + rows_);
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = ptr + cols_ * i;
  }
}

/* Constructor copy */
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(0), cols_(0), matrix_(nullptr) {
  *this = other;
}

/* Constructor move */
S21Matrix::S21Matrix(S21Matrix &&other) : rows_(0), cols_(0), matrix_(nullptr) {
  *this = std::move(other);
}

/* Dectructor */
S21Matrix::~S21Matrix() {
  if (matrix_) {
    delete[] matrix_;
  }
}
/*----------------------------------------------------------------------------*/
/* Присвоение матрице значений другой матрицы */
S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    if (matrix_) {
      delete[] matrix_;
    }
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double *[rows_ * cols_ + rows_]();
    double *ptr = (double *)(matrix_ + rows_);
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = ptr + cols_ * i;
    }
    int value = rows_ * cols_;
    while (value--) {
      matrix_[0][value] = other.matrix_[0][value];
    }
  }
  return *this;
}

/* Присвоение матрице значений другой матрицы перемещением */
S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    if (matrix_) {
      delete[] matrix_;
    }
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }
  return *this;
}

/* Проверяет матрицы на равенство между собой */
bool S21Matrix::EqMatrix(const S21Matrix &other) noexcept {
  bool result = false;
  if ((CheckEqSize(other))) {
    result = true;
    int value = other.rows_ * other.cols_;
    while (value-- && result) {
      if (fabs(matrix_[0][value] - other.matrix_[0][value]) > 1e-7) {
        result = false;
      }
    }
  }
  return result;
}

/* Проверка на равенство матриц (EqMatrix) */
bool S21Matrix::operator==(const S21Matrix &other) noexcept {
  return EqMatrix(other);
}

/* Индексация по элементам матрицы (строка, колонка) */
double &S21Matrix::operator()(int rows, int cols) {
  if (rows < 1 || cols < 1 || rows > rows_ || cols > cols_) {
    throw std::out_of_range("Incorrect input, row or col out of range");
  }
  return matrix_[--rows][--cols];
}

/* Индексация по элементам матрицы (строка, колонка) */
double S21Matrix::operator()(int rows, int cols) const {
  if (rows < 1 || cols < 1 || rows > rows_ || cols > cols_) {
    throw std::out_of_range("Incorrect input, row or col out of range");
  }
  return matrix_[--rows][--cols];
}

/* Прибавляет вторую матрицы к текущей */
void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (!(CheckEqSize(other))) {
    throw std::domain_error("Incorrect input, matrices should be square");
  }
  int value = rows_ * cols_;
  while (value--) {
    matrix_[0][value] = matrix_[0][value] + other.matrix_[0][value];
  }
}

/* Прибавляет вторую матрицы к текущей */
S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

/* Прибавляет вторую матрицы к текущей */
S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result = *this;
  result.SumMatrix(other);
  return result;
}

/* Вычитает из текущей матрицы другую */
void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (!(CheckEqSize(other))) {
    throw std::domain_error("Incorrect input, matrices should be square");
  }
  int value = rows_ * cols_;
  while (value--) {
    matrix_[0][value] = matrix_[0][value] - other.matrix_[0][value];
  }
}

/* Вычитание одной матрицы из другой */
S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

/* Вычитание одной матрицы из другой */
S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result = *this;
  result.SubMatrix(other);
  return result;
}

/* Умножает текущую матрицу на число */
void S21Matrix::MulNumber(const double num) noexcept {
  int value = rows_ * cols_;
  while (value--) {
    matrix_[0][value] = matrix_[0][value] * num;
  }
}

/* Умножает текущую матрицу на число */
S21Matrix &S21Matrix::operator*=(const double num) noexcept {
  MulNumber(num);
  return *this;
}

/* Умножает текущую матрицу на число */
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result = *this;
  result.MulNumber(num);
  return result;
}

/* Умножает текущую матрицу на вторую */
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_) {
    throw std::domain_error(
        "The number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix");
  }
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = result;
}

/* Умножает текущую матрицу на вторую */
S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

/* Умножает текущую матрицу на вторую */
S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result = *this;
  result.MulMatrix(other);
  return result;
}

/* Создает новую транспонированную матрицу из текущей и возвращает ее */
S21Matrix S21Matrix::Transpose() noexcept {
  S21Matrix other(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      other.matrix_[j][i] = matrix_[i][j];
    }
  }
  *this = other;
  return *this;
}

/* Вычисляет и возвращает определитель текущей матрицы */
double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::domain_error("Incorrect input, matrix should be square");
  }
  double det = 0;
  if (rows_ == 1) {
    det = matrix_[0][0];
  } else if (rows_ == 2) {
    det = CalcDeterminant();
  } else {
    for (int i = 0; i < rows_; i++) {
      S21Matrix other(rows_ - 1, cols_ - 1);
      for (int j = 1, k = 0; j < rows_; j++, k = 0) {
        for (int l = 0; l < rows_; l++) {
          if (l == i) continue;
          other.matrix_[j - 1][k] = matrix_[j][l];
          k++;
        }
      }
      det += matrix_[0][i] * (i % 2 == 0 ? 1 : -1) * other.CalcDeterminant();
    }
  }
  return det;
}

/* 	Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает
 * ее */
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::domain_error("Incorrect input, matrix should be square");
  }
  if (rows_ > 1) {
    S21Matrix result(rows_, cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix other(rows_ - 1, cols_ - 1);
        int r = 0, y = 0;
        for (int row = 0; row < rows_; row++) {
          for (int col = 0; col < cols_; col++) {
            if (row != i && col != j) {
              other.matrix_[r][y++] = matrix_[row][col];
              if (y == rows_ - 1) {
                y = 0;
                r++;
              }
            }
          }
        }
        result.matrix_[i][j] = other.Determinant() * pow(-1, i + j);
      }
    }
    *this = result;
  }
  return *this;
}

/* Вычисляет и возвращает обратную матрицу */
S21Matrix S21Matrix::InverseMatrix() {
  double det = 0;
  if (rows_ != cols_ || (det = Determinant()) == 0) {
    throw std::domain_error("Incorrect input, matrix should be square");
  }
  CalcComplements();
  Transpose();
  int value = rows_ * cols_;
  while (value--) {
    matrix_[0][value] = 1 / det * matrix_[0][value];
  }
  return *this;
}
/*----------------------------------------------------------------------------*/
/* Set size matrix */
void S21Matrix::SetSize(int rows, int cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument(
        "Incorrect input, rows should be greater than 0");
  } else if (rows_ != rows || cols_ != cols) {
    S21Matrix other(rows, cols);
    for (int i = 0; i < ((rows > rows_) ? rows_ : rows); i++) {
      for (int j = 0; j < ((cols > cols_) ? cols_ : cols); j++) {
        other.matrix_[i][j] = matrix_[i][j];
      }
    }
    *this = other;
  }
}

/* Заполнение матрицы */
void S21Matrix::FillingMatrix(int mode) {
  int value = rows_ * cols_;
  double count = 1.123456789;
  const double buffer_1[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  const double buffer_2[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  if (mode == kModePosSequence) {
    while (value--) {
      matrix_[0][value] = value + 1;
    }
  } else if (mode == kModePosReversSequence) {
    while (value--) {
      matrix_[0][value] = count++;
    }
  } else if (mode == kModeForResultPos) {
    while (value--) {
      matrix_[0][value] = 26.1234567890;
    }
  } else if (mode == kModeNegSequence) {
    while (value--) {
      matrix_[0][value] = -value - 1;
    }
  } else if (mode == kModeNegReversSequence) {
    while (value--) {
      matrix_[0][value] = -count++;
    }
  } else if (mode == kModeForResultNeg) {
    while (value--) {
      matrix_[0][value] = -26.1234567890;
    }
  } else if (mode == kModeCalcComplements) {
    while (value--) {
      matrix_[0][value] = buffer_1[value];
    }
  } else if (mode == kModeInverseMatrix) {
    while (value--) {
      matrix_[0][value] = buffer_2[value];
    }
  }
}