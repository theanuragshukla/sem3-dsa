#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void printLinkedist(struct node *head);
struct node* createLinkedList(int *arr, int n);

int main(){
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int n = 10;
	struct node *head;
	head = createLinkedList(arr, n);
	printLinkedist(head);
	return 0;
}

struct node* createLinkedList(int *arr, int n){
	struct node *head=NULL, *ret=NULL;
	for(int i=0;i<n;i++){
		struct node *temp =  (struct node*) malloc(sizeof(struct node));
		temp->data = *(arr+i);
		temp->next=NULL;
		if(head!=NULL){
			head-> next = temp;
			head=temp;
			if(i==n-1){
				temp->next=head;
			}
		}
		else{
			head=temp;
			ret=temp;
		}
	}
	return ret;
}

void printLinkedist(struct node *head){
	printf("\n%d ", head->data);
	struct node * temp =head->next;
	while(temp){
		if(temp==head)break;
		printf("%d ", temp->data);
		temp=temp->next;
	}
}


