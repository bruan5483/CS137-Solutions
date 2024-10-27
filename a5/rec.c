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


rectangle intersection(rectangle rects[], int n){
    //note n > 1
    rectangle currIn = rects[0];

    for(int i=1;i<n;i++){
		int x = currIn.bottomLeft.x;
		int y = currIn.bottomLeft.y;
		if(x < rects[i].bottomLeft.x) currIn.bottomLeft.x = rects[i].bottomLeft.x;
		if(y < rects[i].bottomLeft.y) currIn.bottomLeft.y = rects[i].bottomLeft.y;
		if(x+currIn.width > rects[i].bottomLeft.x+rects[i].width){
			currIn.width = rects[i].bottomLeft.x+rects[i].width-currIn.bottomLeft.x;
		} else {
			currIn.width = x+currIn.width-currIn.bottomLeft.x;
		}
		if(y+currIn.height > rects[i].bottomLeft.y+rects[i].height){
			currIn.height = rects[i].bottomLeft.y+rects[i].height-currIn.bottomLeft.y;
		} else {
			currIn.height = y+currIn.height-currIn.bottomLeft.y;
		}

		if(currIn.width<=0 || currIn.height<=0){
			currIn.bottomLeft.x = 0;
			currIn.bottomLeft.y = 0;
			currIn.width = 0;
			currIn.height = 0;
			break;
		}
	}

    return currIn;
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
	

	return 0;
}
*/