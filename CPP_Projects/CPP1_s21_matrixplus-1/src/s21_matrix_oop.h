#ifndef CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_

class S21Matrix {
 public:
  /*--------------------------CONSTRUCTORS---------------------------*/
  S21Matrix();
  S21Matrix(int, int);
  S21Matrix(S21Matrix &&);
  S21Matrix(const S21Matrix &);
  /*----------------------------DESTRUCTOR--------------------------*/
  ~S21Matrix();
  /*----------------------------FUNCTIONS----------------------------*/
  double Determinant();
  S21Matrix InverseMatrix();
  S21Matrix CalcComplements();
  S21Matrix Transpose() noexcept;
  void SumMatrix(const S21Matrix &);
  void SubMatrix(const S21Matrix &);
  void MulMatrix(const S21Matrix &);
  void MulNumber(const double) noexcept;
  bool EqMatrix(const S21Matrix &) noexcept;
  /*------------------------OVERLOADS-FUNCTIONS----------------------*/
  double &operator()(int, int);
  S21Matrix operator*(const double);
  double operator()(int, int) const;
  S21Matrix operator+(const S21Matrix &);
  S21Matrix operator-(const S21Matrix &);
  S21Matrix operator*(const S21Matrix &);
  S21Matrix &operator=(const S21Matrix &);
  S21Matrix &operator+=(const S21Matrix &);
  S21Matrix &operator-=(const S21Matrix &);
  S21Matrix &operator*=(const S21Matrix &);
  S21Matrix &operator=(S21Matrix &&) noexcept;
  bool operator==(const S21Matrix &) noexcept;
  S21Matrix &operator*=(const double) noexcept;
  /*------------------------------GENERAL---------------------------*/
  void SetSize(int, int);
  void FillingMatrix(int);
  /* Return number of rows */
  inline int GetRows() { return rows_; }
  /* Return number of columns */
  inline int GetCols() { return cols_; }

 private:
  int rows_, cols_;
  double **matrix_;
  /* Calculate determinant for 2x2 matrix */
  inline double CalcDeterminant() {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  }
  /* Return 1 if size of matrix equal, else 0 */
  inline bool CheckEqSize(const S21Matrix &other) {
    return (other.rows_ == rows_ && other.cols_ == cols_) ? true : false;
  }
};
/*------------------ENUM FLAGS FOR FILLING MATRIX------------------*/
enum Flags {
  kModePosSequence = 1,
  kModePosReversSequence = 2,
  kModeForResultPos = 3,
  kModeNegSequence = 4,
  kModeNegReversSequence = 5,
  kModeForResultNeg = 6,
  kModeCalcComplements = 7,
  kModeInverseMatrix = 8
};
/*------------------------------------------------------------------*/
#endif  // CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_OOP_H_