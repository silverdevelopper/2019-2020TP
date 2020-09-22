/*
 * main.c
 *
 *  Created on: Mar 14, 2019
 *      Author: Merve Unlu
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "stack.h"
#include "rpn.h"

#define LINE_MAX 10

int main(int argc, char *argv[])
{
	/*
	 * Hesaplanmasi icin bir tanim degerini
	 * kullanicidan alir ve daha once tanimli
	 * fonksiyonlari cagirip hesaplar.
	 * Kullanici sistemden cikis yapmak icin exit yazip Enter a basmalidir.
	 */
	int continuing = 1;
	char line[LINE_MAX];
        // Alistirma 1.f
        // stack.c yazdiginiz fonksiyonlari test edin.
		struct stackNode *ust;
		ust=malloc(sizeof(struct stackNode));
		stack_push(&ust,17);
		stack_push(&ust,12);
		stack_push(&ust,11);
		stack_push(&ust,18);
		stack_push(&ust,17);
		stack_print(ust);
		stack_pop(&ust);
		stack_print(ust);
		ust=stack_multi_pop(ust,3);
		stack_print(ust);
        // Alistirma 2.b yi tamamladiktan sonra alttaki satiri 
        // yorumdan cikarip test yapabilirsiniz.
        // Alistirma 2.c
        //rpn_test_evaluate_RPN();

	    struct stackNode *stack = NULL;

	    printf("RPN Hesap Makinesi\nCikis icin exit yazip ENTER'a basin\n\n");

            // Alistirma 3   

	    printf("Hesaplama isleminden cikildi.\n");
return 0;
}
