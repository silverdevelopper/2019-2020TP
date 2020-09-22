/*
 * rpn.h
 *
 *  Created on: Mar 14, 2019
 *      Author: Merve Unlu
 */

#include"stack.h"

#ifndef _RPN_H_
#define _RPN_H_

double evaluate_RPN(char *expr, struct stackNode **top);
double compute_operation(double op1, double op2, char operation);
#endif
