#include <stdio.h>
#include <assert.h>


typedef struct Point{
	int x;
	int y;
} point;

typedef struct Rectangle {
   point bottomLeft;
   int width;
   int height;
} rectangle;

int max(int a, int b){
    return a > b ? a : b;
}

int min(int a, int b){
    return a < b ? a : b;
}

rectangle intersection(rectangle rects[], int n){
    //note n > 1
    rectangle inter = rects[0];
    for (int i=1; i<n; i++){
        point bottom = {max(inter.bottomLeft.x,rects[i].bottomLeft.x), max(inter.bottomLeft.y,rects[i].bottomLeft.y)};
        inter.width = min(inter.bottomLeft.x + inter.width, rects[i].bottomLeft.x + rects[i].width) - bottom.x;
        inter.height = min(inter.bottomLeft.y + inter.height, rects[i].bottomLeft.y + rects[i].height) - bottom.y;
        inter.bottomLeft = bottom;
        if (inter.width < 0 || inter.height < 0){
            inter.bottomLeft.x = 0;
            inter.bottomLeft.y = 0;
            inter.height = 0;
            inter.width = 0;
        }
    }
    return inter;
}
/*
int main(){
	
	rectangle result;

	rectangle r = {{2,6},3,4};
	rectangle s = {{0,7},7,1};
	rectangle t = {{3,5},1,6};
	rectangle u = {{5,6},3,4};
	
	// Test 1
	rectangle rects1[2] = {r, s};
	result = intersection(rects1, 2);
	
	assert(result.bottomLeft.x == 2);
	assert(result.bottomLeft.y == 7);
	assert(result.width == 3);
	assert(result.height == 1);
	

	// Test 2
	rectangle rects2[3] = {r, s, t};
	result = intersection(rects2, 3);
	assert(result.bottomLeft.x == 3);
	assert(result.bottomLeft.y == 7);
	assert(result.width == 1);
	assert(result.height == 1);
	
	
	// Test 3
	rectangle rects3[4] = {r, s, t, u};
	result = intersection(rects3, 4);
	assert(result.bottomLeft.x == 0);
	assert(result.bottomLeft.y == 0);
	assert(result.width == 0);
	assert(result.height == 0);

	// Test 4
	rectangle a = {{0,0},1,1};
	rectangle b = {{1,1},1,1};
	rectangle rects4[2] = {a,b};
    result = intersection(rects4, 2);
	assert(result.bottomLeft.x == 1);
	assert(result.bottomLeft.y == 1);
	assert(result.width == 0);
	assert(result.height == 0);
	

	return 0;
}
*/