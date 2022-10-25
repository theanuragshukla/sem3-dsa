#include <stdio.h>

int main (){
	int arr[] = {13,9,4,1,8, 2, 7 , 6,3, 11, 10, 12  };
	int len = 12;

	// method 1 -> new Array

	int newArr[len+1];
	for(int i = 0; i< len;i++){
		newArr[arr[i]-1] = -1;
	}
	for(int i = 0; i<len+1;i++){
		if(newArr[i]!=-1){
			printf("%d is missing\n", i+1);
			break;
		}
	}

	// method 2 -> XOR 

	int xor = 0;
	for(int i = 0; i<len;i++){
		xor^=arr[i]^(i+1);
	}
	printf("%d is missing\n", xor^(len+1));

	// method 3 -> formula

	int tempSum = 0;
	int sum = (len+1)*(len+2)/2;
	for(int i = 0; i< len ; i++){
		tempSum+=arr[i];
	}
	printf("%d is missing\n", sum-tempSum);
	




	return 0;
}
