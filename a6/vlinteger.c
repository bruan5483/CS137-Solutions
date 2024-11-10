
#include "vlinteger.h"
#include <stdlib.h>
#include <stdio.h>



struct linteger *vlintegerCreate(void)
{
	struct linteger *t1 = malloc(sizeof(struct linteger));
	t1->arr = NULL;
	t1->length = 0;	// no values in t1.
	return t1;
}

void vlintegerPrint(struct linteger *t1)
{
	printf("length=%d\n", t1->length);
	for (int i = 0; i < t1->length; ++i)
	{
		printf("%d", t1->arr[i]);
	}
	printf("\n");
}

void vlintegerDestroy(struct linteger *t1)
{
	if (t1)
	{
		free(t1->arr);	// free the inside array first
		free(t1);	// then free the structure
	}
}

void vlintegerRead(struct linteger *t1)
{   
	int digit;
	while (scanf("%d", &digit)) {
        t1->arr = realloc(t1->arr, ++t1->length * sizeof(int));
        t1->arr[t1->length - 1] = digit;
    }
}

struct linteger *vlintegerAdd(struct linteger *t1, struct linteger *t2)
{	
	struct linteger *a = vlintegerCreate();
	a->length = (t1->length > t2->length ? t1->length : t2->length)+1;
	int small = t1->length < t2->length ? t1->length : t2->length;
	//a->arr = malloc((a->length)*sizeof(int));
	a->arr = calloc(a->length,sizeof(int));
	for(int i=0;i<small;i++){
		int sum = *(t1->arr + (t1->length-1-i)) + *(t2->arr + (t2->length-1-i));
		//printf("SUM: %d\n",sum);
		*(a->arr+(a->length-1-i)) += sum;
		if (*(a->arr+(a->length-1-i))>=10){
			*(a->arr+(a->length-1-i)) -=10;
			*(a->arr+(a->length-2-i)) += 1;
		}
	}
	
	if(t1->length < a->length-1){
		for(int i=0;i<t2->length-t1->length;i++){
			*(a->arr+i+1) += *(t2->arr+i);
		}
	} else if (t2->length < a->length-1){
		for(int i=0;i<t1->length-t2->length;i++){
			*(a->arr+i+1) += *(t1->arr+i);
		}
	}

	if (*(a->arr)==0){
		int *ar = malloc((a->length-1)*sizeof(int));
		for(int j=0; j<a->length-1; j++){
			*(ar + j) = *(a->arr + j + 1);
		}
		free(a->arr);
		a->arr = ar;
		a->length -= 1;
	}

	return a;
}
