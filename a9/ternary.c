#include <stdio.h>
#include <assert.h>

int help(int L[], int beginning, int end, int target, int last_occur){
	if(beginning > end) return last_occur;

	int mid1 = beginning + (end - beginning)/3;
	int mid2 = end - (end - beginning)/3;

	printf("Examining indices %d and %d\n", mid1, mid2);

	if(mid2==end && L[mid2]==target) return mid2;

	if(L[mid2]==target) return help(L,mid2+1,end,target,mid2);
	else if (L[mid2]<target) return help(L,mid2+1,end,target,last_occur);
	else if(L[mid1]==target) return help(L,mid1+1,mid2-1,target,mid1);
	else if(L[mid1]<target) return help(L,mid1+1,mid2-1,target,last_occur);
	else return help(L,beginning,mid1-1,target,last_occur);
}


int ternarylastsearch(int L[], int len, int target){
	if (len < 1) return -1; // In case there is some problem with len
	return help(L,0,len-1,target,-1);
}

int main(void) {
   
    int a[10] = {1, 2, 3, 4, 5, 6, 6, 6, 9, 100};
    assert(7 == ternarylastsearch(a,10,6));

	printf("\n");
	int a2[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    assert(-1 == ternarylastsearch(a2,10,100));
	printf("\n");
	assert(-1 == ternarylastsearch(a2,10,11));
	printf("\n");
	assert(0 == ternarylastsearch(a2,10,2));

	printf("\n");
	int a3[12] = {6,6,6,6,6,6,6,6,6,6,6,6};
    assert(11 == ternarylastsearch(a3,12,6));

	printf("\n");
	int t1[1] = {5};
	assert(0 == ternarylastsearch(t1,1,5));

	printf("\n");
	int t2[6] = {3,4,4,5,6,6};
	assert(0 == ternarylastsearch(t2,6,3));
	printf("\n");
	assert(5 == ternarylastsearch(t2,6,6));
	printf("\n");
	assert(2 == ternarylastsearch(t2,6,4));

	printf("\n");
	int t3[5] = {1,2,2,2,3};
	assert(3 == ternarylastsearch(t3,5,2));
	printf("\n");
	assert(-1 == ternarylastsearch(t3,5,4));

    return 0;
}
