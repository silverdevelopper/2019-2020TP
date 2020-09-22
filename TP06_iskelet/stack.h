/*
 * stack.h
 *
 *  Created on: Mar 14, 2019
 *      Author: Merve Unlu
 */

#ifndef _STACK_H_
#define _STACK_H_

struct stackNode {
    double data;
    struct stackNode *next;
};
struct stackNode* stack_multi_pop(struct stackNode *top,int k);
void stack_push(struct stackNode **top, double data);
void stack_print(struct stackNode *top);
double stack_pop(struct stackNode **top);
void stack_free(struct stackNode **top);
int is_empty(struct stackNode *top);
/*
 * Alistirma 1.d 
 * stack_multi_pop fonksiyonunu tanimlayiniz.
 */ 

#endif
