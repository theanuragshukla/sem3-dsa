#include <stdio.h>
#include <stdlib.h>
#define size 5


int getdata(int transformedMat[], int i, int j){
	if(i<j){
		return 0;
	}
	int idx = j*(j+1)/2+i;
	return transformedMat[idx];
}

void printArray(int arr[], int len){
	for(int i = 0;i<len;i++){
		printf("%d ", arr[i]);
	}
}
int main (){
	int mat [size][size]  = {
		{9,2,5,4,6},
		{0,6,3,7,9},
		{0,0,5,4,3},
		{0,0,0,4,6},
		{0,0,0,0,7},
	};

	int *transformedMat;
	transformedMat=(int*)calloc(1, sizeof(int));
	int len = 0;
	for(int i = 0;i<size;i++){
		for(int j=0;j<size;j++){
			if(mat[i][j]!=0){
				len++;
				transformedMat = (int *)realloc(transformedMat, sizeof(int)*len);
				transformedMat[len-1] = mat[i][j];
			}
		}
	}
	printf("mat[%d][%d] = %d\n",0,4,getdata(transformedMat, 0, 4));
	printf("mat[%d][%d] = %d\n", 3 , 1, getdata(transformedMat, 3, 1));
	printArray(transformedMat,len);
	return 0;
}
