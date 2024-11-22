// #include ...


int ternarylastsearch(int L[], int len, int target){
	
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

    return 0;
}


