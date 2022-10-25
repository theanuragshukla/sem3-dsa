#include <stdio.h>
#include <stdlib.h>

void printArray(int * arr, int len);

int insert(int arr[], int len , int idx, int value);
int deleteByIndex(int arr[], int len, int idx);
int searchArray(int arr[], int len, int data);
int binarySearch(int * arr, int n, int val);

int main(){
	int arrTemp[] = {1,3,4,56,32,6,24,97,11,7,8,134,86,19,73};
	int len = sizeof(arrTemp)/sizeof(int);
	int * arr = (int *)malloc(sizeof(int)*len);
	for(int i = 0; i < len;i++){
		*(arr+i)=arrTemp[i];
	}
	printArray(arr, len);
	len=insert(arr, len, 3, -1);
	printArray(arr, len);
	len=insert(arr, len, 0, -2);
	printArray(arr, len);
	len=insert(arr, len, len, -3);
	printArray(arr, len);
	len = deleteByIndex(arr, len, 3);
	printArray(arr, len);
	len = deleteByIndex(arr, len, 0);
	printArray(arr, len);
	len = deleteByIndex(arr, len, len-1);
	printArray(arr, len);
	return 0;

}

int binarySearch(int * arr, int n, int val){
	int min = 0;
	int max = n-1;
	while(min<=max){
		int mid = min + (max-min)/2;
		int temp = arr[mid];
		if(temp==val){
			return mid;
		}else if(temp < val){
			max=mid-1;
		}else{
			min=mid+1;
		}
	}
	return -1;
}
void printArray(int arr[] , int len){
	for(int i = 0; i< len;i++){
		printf("%d ", *(arr+i));
	}
	printf("\n");
}
int insert(int arr[], int len , int idx, int value){
	arr = (int *)realloc(arr, (sizeof(int)*(len+1)));
	for(int j = len;j>=idx;j--){
		arr[j+1] = arr[j];
	}
	arr[idx] = value;
	return len+1;

}

int deleteByIndex(int arr[], int len, int idx){
	for(int i = idx+1; i< len;i++){
		arr[i]=arr[i+1];
	}
	return (len-1);
}

int searchArray(int arr[], int len, int data){
    for (int i = 0; i < len; i++)
        if (arr[i] == data)
            return i;
    return -1;
}


