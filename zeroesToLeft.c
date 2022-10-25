#include <stdio.h>

void zeroesToLeft(int* arr, int len);
void printArray(int * arr, int len);
int main(){
	int arr[] = {0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,0,1,1,0,0,1};
	int len = sizeof(arr)/sizeof(int);
	printArray(arr, len);
	zeroesToLeft(arr, len);
	printArray(arr, len);
	return 0;
}

void zeroesToLeft(int* arr, int len) {
	int j = 0;
	for(int i = 0 ; i< len ; i++){
		if(*(arr+i)==0){
			int temp = *(arr+j);
			*(arr+j++) = 0;
			*(arr+i) = temp;
		}
	}
}

void printArray(int arr[] , int len){
	for(int i = 0; i< len;i++){
		printf("%d ", *(arr+i));
	}
	printf("\n");
}
