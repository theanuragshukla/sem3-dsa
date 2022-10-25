#include<stdio.h>
#include<stdlib.h>
typedef struct node node ;
typedef struct doublyLL dll ;
struct node{
	int data;
	node *next;
	node *prev;
};
struct doublyLL{
	node *head;
	node *tail;
};

void printLinkedist(dll *ll);
void printLinkedistReverse(dll *ll);
dll* createLinkedList(int *arr, int n);
dll* addFirst(dll *ll, int n);
dll* addLast(dll *head, int n);
dll* deleteFirst(dll *head);
dll* deleteLast(dll *head);
dll* deleteNode(dll *head, int val);
dll* insertNodeAt(dll *head,int idx,  int val);
dll* deleteNodeAt(dll *head,int idx);
dll* reverse(dll *ll);

int main(){
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int n = 10;
	dll *ll;
	ll = createLinkedList(arr, n);
	printLinkedist(ll);
	printLinkedistReverse(ll);
	ll = addFirst(ll, -1);
	printLinkedist(ll);
	ll = addLast(ll, 10);
	printLinkedist(ll);
	ll=deleteFirst(ll);
	printLinkedist(ll);
	ll=deleteLast(ll);
	printLinkedist(ll);
	ll = deleteNode(ll, 5);
	printLinkedist(ll);
	ll = deleteNode(ll, 0);
	printLinkedist(ll);
	ll = deleteNode(ll, 10);
	printLinkedist(ll);
	ll = insertNodeAt(ll, 0, -1);
	printLinkedist(ll);
	ll = insertNodeAt(ll, 8, 67);
	printLinkedist(ll);
	ll = insertNodeAt(ll, 5, -656);
	printLinkedist(ll);
	ll=deleteNodeAt(ll, 0);
	printLinkedist(ll);
	ll=deleteNodeAt(ll, 8);
	printLinkedist(ll);
	ll=deleteNodeAt(ll, 5);
	printLinkedist(ll);
	ll= reverse(ll);
	printLinkedistReverse(ll);
	return 0;
}

dll* createLinkedList(int *arr, int n){
	dll *ret = (dll *)malloc(sizeof(dll));
	node *head=NULL, *temp;
	for(int i=0;i<n;i++){
		temp =  (node*) malloc(sizeof(node));
		temp->data = *(arr+i);
		temp->next=NULL;
		temp->prev=NULL;
		if(head!=NULL){
			temp->prev=head;
			head-> next = temp;
			head=temp;
		}
		else{
			head=temp;
			ret->head = temp;
		}
	}
	ret->tail=temp;
	return ret;
}

void printLinkedist(dll *ll){
	printf("\n");
	node *head = ll->head;
	while(head!=NULL){
		printf("%d ", head->data);
		head=head->next;
	}
	free(head);
}

void printLinkedistReverse(dll *ll){
	printf("\n");
	node *tail = ll->tail;
	while(tail!=NULL){
		printf("%d ", tail->data);
		tail=tail->prev;
	}
	free(tail);
}


dll* addFirst(dll *ll, int n){
	node *temp = (node*) malloc(sizeof(node));
	temp->data=n;
	temp->next = ll->head;
	temp->prev=NULL;
	ll->head->prev=temp;
	ll->head=temp;
	return ll;
}

dll* addLast(dll *ll, int n){
	node *temp = (node*) malloc(sizeof(node));
	temp->data=n;
	temp->next = NULL;
	temp->prev=ll->tail;
	ll->tail->next=temp;
	ll->tail=temp;
	return ll;
}

dll* deleteFirst(dll *ll){

	if(ll->head==NULL || ll->head->next==NULL)return NULL;
	node *temp = ll->head;
	ll->head = ll->head->next;
	free(temp);
	return ll;
}
dll* deleteLast(dll *ll){
	node *temp = (node*) malloc(sizeof(node));
	if(ll->head==NULL || ll->head->next==NULL)return NULL;
	temp = ll->tail;
	ll->tail=ll->tail->prev;
	ll->tail->next=NULL;
	free(temp);
	return ll;
}

dll* deleteNode(dll *ll, int val){
	if(ll->head->data==val){
		return deleteFirst(ll);
	}
	node *temp = ll->head->next;
	while(temp!=NULL){
		if(temp->data == val){
			temp->prev->next = temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			break;
		}
		temp=temp->next;

	}
	return ll;
}

dll* insertNodeAt(dll *ll,int idx,  int val){
	if(idx==0){
		return addFirst(ll, val);
	}
	int count = 0;
	node *temp = ll->head;
	while(temp!=NULL){
		if(count==idx-1){
			node *newNode = (node *)malloc(sizeof(node));
			newNode->data = val;
			newNode->next = temp->next;
			temp->next=newNode;
			newNode->prev = temp;
			temp->next->prev=newNode;
			break;
		}
		temp=temp->next;
		count++;
	}
	return ll;
}

dll* deleteNodeAt(dll *ll,int idx){
	if(idx==0)return deleteFirst(ll);
	int count = 0;
	node *temp = ll->head;
	while(temp!=NULL){
		if(count==idx-1){
			node *toFree = temp->next;
			temp->next=toFree->next;
			temp->next->prev=temp;
			free(toFree);
			break;
		}
		temp=temp->next;
		count++;
	}

	return ll;
}

dll* reverse(dll* ll){
	node *temp = NULL;
	node *curr = ll->head;
	ll->tail=curr;
	 while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
	 printf("\n%d\n", temp->prev->data);
	 ll->head=temp->prev;
	 return ll;
}


