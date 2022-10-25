#include <stdio.h>

int linearSearch(int * arr, int len, int val);
int binarySearch(int * arr, int len, int val);

int main (){
	int arr[]= {54,35,25,6,75,2,75,33,67,3,12,9,76};
	int arr2[] = {1,2,3,4,5,6,7,8,9};
	int len = 13;
	printf("the index of %d is %d\n", 75,linearSearch(arr, len,  75) );
	printf("the index of %d is %d\n", 5, binarySearch(arr2,9,  5) );
	
	return 0;	
}

int linearSearch(int * arr, int len , int val ){
	for (int i = 0; i< len;i++){
		if(*(arr+i)==val)return i;
	}
	return -1;
}
int binarySearch(int *arr, int len, int val){
	int min = 0;
	int max = len-1;
	while( min<=max){
		int mid = min+(max-min)/2;
		int temp = *(arr+mid);
		if(temp == val)return mid;
		else if (temp<val)min=mid+1;
		else max = mid-1;
	}
	return -1;
}
