#include <stdio.h>
#include <stdlib.h>
#define size 5


int getdata(int transformedMat[], int i, int j){
	if(i!=j){
		return 0;
	}
	return transformedMat[i];
}

void printArray(int arr[], int len){
	for(int i = 0;i<len;i++){
		printf("%d ", arr[i]);
	}
}
int main (){
	int mat [size][size]  = {
		{1,0,0,0,0},
		{0,2,0,0,0},
		{0,0,3,0,0},
		{0,2,0,4,0},
		{0,0,0,0,5},
	};

int *transformedMat;
transformedMat=(int*)malloc(sizeof(int)*size);
int len = size;
	for(int i = 0;i<size;i++){
		for(int j=0;j<size;j++){
			if(mat[i][j]!=0){
				transformedMat[i] = mat[i][j];
			}
		}
	}
	printf("\nmat[%d][%d] = %d\n",1,2,getdata(transformedMat, 1, 2));
	printf("\nmat[%d][%d] = %d\n", 2,2, getdata(transformedMat, 2,2));
	return 0;
}
