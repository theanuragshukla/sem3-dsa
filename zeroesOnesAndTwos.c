#include <stdio.h>

void sort(int* arr, int len);
void printArray(int * arr, int len);
int main(){
	int arr[] = {0,2,1,1,0,1,2,1,0,2,1,0, 2,0};
	int len = sizeof(arr)/sizeof(int);
	printArray(arr, len);
	sort(arr, len);
	printArray(arr, len);
	return 0;
}

void sort(int* arr, int len) {
	int j = 0;
	for(int i = 0 ; i< len ; i++){
		if(*(arr+i)==0){
			int temp = *(arr+j);
			*(arr+j++) = 0;
			*(arr+i) = temp;
		}
	}
	j=len-1;
	for(int i = len - 1 ; i >= 0 ; i--){
		if(*(arr+i)==2){
			int temp = *(arr+j);
			*(arr+j--) = 2;
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
