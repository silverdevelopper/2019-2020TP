/*
 * heap.h
 *
 *  Created on: May 2, 2019
 *      Author: Merve Unlu
 */
#include<stdlib.h>
#include<stdio.h>
#include<math.h>


#ifndef HEAP_H_
#define HEAP_H_

void print_heap(int* array,int size);
void max_heapify_recursive(int *array,int indeks,int size);
void build_max_heap(int *array,int size);
void heap_sort(int *array, int size);
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1);
#endif /* HEAP_H_ */
