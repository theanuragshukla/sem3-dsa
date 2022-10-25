#include <stdio.h>
int main(){
	int n ;
	printf("enter matrix order: ");
	scanf("%d", &n);
	printf("BA");
	for(int i=0;i<n;i++)
		printf(" + ( a%d - lb%d )", i+1,i+1);
	return 0;
}
