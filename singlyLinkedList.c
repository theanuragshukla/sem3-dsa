#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void printLinkedist(struct node *head);
struct node* createLinkedList(int *arr, int n);
struct node* addFirst(struct node *head, int n);
struct node* addLast(struct node *head, int n);
struct node* deleteFirst(struct node *head);
struct node* deleteLast(struct node *head);
struct node* deleteNode(struct node *head, int val);
struct node* insertNodeAt(struct node *head,int idx,  int val);
struct node* deleteNodeAt(struct node *head,int idx);
struct node* commonNode(struct node *head1 ,struct node * head2);
struct node* reverse(struct node *head);
struct node* detectCycle(struct node *head);
struct node* nodeFromLast(struct node *head, int n);

int main(){
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int n = 10;
	struct node *head;
	head = createLinkedList(arr, n);
	printLinkedist(head);
	head = addFirst(head, -1);
	printLinkedist(head);
	head = addLast(head, 10);
	printLinkedist(head);
	head=deleteFirst(head);
	printLinkedist(head);
	head=deleteLast(head);
	printLinkedist(head);
	head = deleteNode(head, 5);
	printLinkedist(head);
	head = deleteNode(head, 0);
	printLinkedist(head);
	head = deleteNode(head, 10);
	printLinkedist(head);
	head = insertNodeAt(head, 0, -1);
	printLinkedist(head);
	head = insertNodeAt(head, 8, 67);
	printLinkedist(head);
	head = insertNodeAt(head, 5, -656);
	printLinkedist(head);
	head=deleteNodeAt(head, 0);
	printLinkedist(head);
	head=deleteNodeAt(head, 8);
	printLinkedist(head);
	head=deleteNodeAt(head, 5);
	printLinkedist(head);
	struct node * lastNNode = nodeFromLast(head, 4);
	printf("\n%dth node from end contains %d", 4, lastNNode->data);
	struct node *head1 = addFirst(head, 564);
	head1 = addFirst(head1, 96);
	head1 = addFirst(head1, -857);
	head1 = addFirst(head1, -8675);
	head1 = addFirst(head1, 5645);
	struct node *nodeCommon = commonNode(head, head1);
	printf("\n%d", nodeCommon->data);
	head= reverse(head);
	printLinkedist(head);
	struct node *tail = head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=head->next->next->next;

	struct node *loopNode = detectCycle(head);
	if(loopNode == NULL){
		printf("\nno cycle detected");
	}else{
		printf("\nCycle detected at node with value %d", loopNode->data);
	}
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
		}
		else{
			head=temp;
			ret=temp;
		}
	}
	return ret;
}

void printLinkedist(struct node *head){
	printf("\n");
	while(head!=NULL){
		printf("%d ", head->data);
		head=head->next;
	}
}


struct node* addFirst(struct node *head, int n){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data=n;
	temp->next = head;
	return temp;
}

struct node* addLast(struct node *head, int n){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data=n;
	temp->next = NULL;
	struct node *curr = head;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=temp;
	return head;
}

struct node* deleteFirst(struct node *head){
	if(head==NULL || head->next==NULL)return NULL;
	struct node *ret = head->next;
	free(head);
	return ret;
}
struct node* deleteLast(struct node *head){
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	if(head==NULL || head->next==NULL)return NULL;
	temp = head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	struct node *toFree = temp->next;
	temp->next=NULL;
	free(toFree);
	return head;
}

struct node* deleteNode(struct node *head, int val){
	if(head->data==val){
		struct node *toFree = head;
		struct node *ret = head->next;
		free(toFree);
		return ret;
	}
	struct node *temp = head;
	struct node *prev = head;
	while(temp!=NULL){
		if(temp->data == val){
			struct node *toFree = temp;
			prev->next = temp->next;
			free(toFree);
			break;
		}
		prev=temp;
		temp=temp->next;
	}
	return head;
}

struct node* insertNodeAt(struct node *head,int idx,  int val){
	if(idx==0){
		return addFirst(head, val);
	}
	int count = 0;
	struct node *temp = head;
	while(temp!=NULL){
		if(count==idx-1){
			struct node *newNode = (struct node*)malloc(sizeof(struct node));
			newNode->data = val;
			newNode->next = temp->next;
			temp->next=newNode;
			break;
		}
		temp=temp->next;
		count++;
	}
	return head;
}

struct node* deleteNodeAt(struct node *head,int idx){
	if(idx==0)return deleteFirst(head);
	int count = 0;
	struct node *temp = head;
	while(temp!=NULL){
		if(count==idx-1){
			struct node *toFree = temp->next;
			temp->next=toFree->next;
			free(toFree);
			break;
		}
		temp=temp->next;
		count++;
	}

	return head;
}


struct node* nodeFromLast(struct node *head, int n){
	struct node *temp = (struct node *) malloc(sizeof(struct node));
	temp=head;
	int len = 0;
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}
	if(n>len){
		return NULL;
	}
	temp=head;
	for(int i = 0; i<(len-n);i++){
		temp=temp->next;
	}
	return temp;
}
struct node* commonNode(struct node *head1 ,struct node * head2){
	int len1, len2;
	struct node *temp, *temp1;
	temp = head1;
	while(temp!=NULL){
		len1++;
		temp=temp->next;
	}
	temp = head2;
	while(temp!=NULL){
		len2++;
		temp=temp->next;
	}
	int lenDiff = len1 > len2 ? (len1-len2) : (len2-len1);
	temp = len1>len2 ? head1 : head2;
	temp1 = len1>len2 ? head2 : head1;
	while(lenDiff--){
		if(temp==temp1){
			return temp;
		}
		temp=temp->next;
	}
	while(len1-- && len2--){
		if(temp==temp1){
			return temp;
		}
		temp=temp->next;
		temp1=temp1->next;
	}
	return NULL;
}

struct node* reverse(struct node *head){
	/*
	 *if(head==NULL || head->next==NULL){
	 *    return head;
	 *}
	 *struct node *temp = reverse(head->next);
	 *head->next->next=head;
	 *head->next = NULL;
	 *return temp;
	 */
	struct node *prev =NULL;
	struct node *temp = NULL;
	struct node *curr = head;
	while(curr!= NULL){
		temp= curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	return prev;
}
struct node* detectCycle(struct node *head){
	struct node *p1 = head;
	struct node *p2 = head;
	while(p1!=NULL && p2!=NULL && p2->next!=NULL){
		p1=p1->next;
		p2=p2->next->next;
		if(p1==p2){
			p1=head;
			while(p1!=p2){
				p1=p1->next;
				p2=p2->next;
			}
			return p1;
		}
	}
	return NULL;
}


