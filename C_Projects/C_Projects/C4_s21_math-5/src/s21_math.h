#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdbool.h>
#include <stdio.h>

#define S21_POSINF 1.0/0.0
#define S21_NEGINF -1.0/0.0
#define S21_NAN 0.0/0.0
#define S21_PI 3.1415926535897932384626433832795
#define S21_LDMAX 1.79769e+308
#define S21_LDMIN -1.79769e+308
#define S21_E 1e-10
#define S21_EULER 2.7182818284590452353602874713527

int s21_abs(int x);                            
long double s21_acos(double x);                
long double s21_asin(double x);                
long double s21_atan(double x);                
long double s21_ceil(double x);                
long double s21_cos(double x);                 
long double s21_exp(double x);                 
long double s21_fabs(double x);                
long double s21_floor(double x);               
long double s21_fmod(double x, double y);      
long double s21_log(double x);                 
long double s21_pow(double base, double exp);  
long double s21_sin(double x);                 
long double s21_sqrt(double x);                
long double s21_tan(double x);                 

#endif