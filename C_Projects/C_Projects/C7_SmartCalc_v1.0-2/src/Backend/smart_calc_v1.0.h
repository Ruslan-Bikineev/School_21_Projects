#ifndef SMART_CALC_V1_0_H
#define SMART_CALC_V1_0_H
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--------------------------------DATA---------------------------------*/
struct data {
  double value;
  int priority;
  int type;
};
typedef struct data DATA;
typedef DATA *DATAPTR;
/*--------------------------------STACK--------------------------------*/
struct stack_node {
  DATAPTR data;
  struct stack_node *next_ptr;
};
typedef struct stack_node STACKNODE;
typedef STACKNODE *STACKNODEPTR;
/*-------------------------------MACROS--------------------------------*/
#define OK 0
#define FAIL 1
#define PRECISION 1e-7
/*---------------------------------------------------------------------*/
#define ERROR_1 1  // error in brackets
#define ERROR_2 2  // error in parser
#define ERROR_3 3  // error DIV on 0
#define ERROR_4 4  // malloc return NULL
/*---------------------------------------------------------------------*/
#define NUMBER 0
#define ADD 1
#define SUB 2
#define MULT 3
#define DIV 4
#define POW 5
#define MOD 6
#define COS 7
#define SIN 8
#define TAN 9
#define ACOS 10
#define ASIN 11
#define ATAN 12
#define SQRT 13
#define LN 14
#define LOG 15
#define UNARNY_MINUS 16
#define OPEN_BRACKET 17
#define CLOSE_BRACKET 18
/*-------------------------SMART_CALC_FUNCTION------------------------*/
void smart_calc(char *, int *, double, double *);
/*---------------------------STACK_FUNCTIONS---------------------------*/
void pop(STACKNODEPTR *);
DATAPTR peek(STACKNODEPTR);
int is_empty(STACKNODEPTR);
void destroy_stack(STACKNODEPTR *);
void turn_over_stack(STACKNODEPTR *, int *);
void push(STACKNODEPTR *, double, int, int, int *);
/*--------------------------SUPPORT_FUNCTIONS--------------------------*/
bool is_digit(char *);
void check_brackets(char *, int *);
void polish_notation(STACKNODEPTR *, int *);
void calculate(STACKNODEPTR *, double *, int *);
double data_value_return(STACKNODEPTR *, int *);
void parser(STACKNODEPTR *, char *, double, int *);
void check_functions(STACKNODEPTR *, char **, int *);
void compute_functions(STACKNODEPTR *, STACKNODEPTR *, int *);
void check_arifmetic_operations(STACKNODEPTR *, char **, int *);
void compute_arifmetic_operations(STACKNODEPTR *, STACKNODEPTR *, int *);
/*---------------------------------------------------------------------*/
#endif