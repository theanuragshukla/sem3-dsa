#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int l;
    int *arr;
};

void printQ(struct queue *q){
	for(int i = 0; i<q->size;i++){
		printf("%d ", q->arr[i]);
	}
	printf("\n");
}

int isQfull(struct queue *q)
{
	if (q->f == q->size - 1)
	{
		return 1;
	}
	return 0;
}

int isQempty(struct queue *q)
{
	if ( q->f==-1)
	{
		printf("The queue is empty!\n");
		return 1;
	}
	return 0;
}

void enqueue(struct queue *q, int element)
{
	if (isQfull(q))
	{
		printf("Sorry the queue is full\n");
	}
	else
	{

		q->f = ++(q->f);
		q->arr[q->f] = element;
		printf("Successfully Enqueued\n");

	}
}

int dequeue(struct queue *q){
	int ans=-1;
 if (isQempty(q))
 {
	 printf("No element found to dequeue\n");
   
 }
 else{
	 q->arr[q->f]=0;
	 q->f=--(q->f);
	printf("Successfully Dequeued\n");

	 ans= q->arr[q->f];
 }
 return ans;
 
}



int main()
{
struct queue *q = (struct queue *) malloc(sizeof(struct queue));	
    q->f = -1;
	q->l = -1;
    q->size = 10;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q,12);
	printQ(q);
	enqueue(q,13);
	printQ(q);
	dequeue(q);
	printQ(q);
	dequeue(q);
	printQ(q);
	isQempty(q);
	printQ(q);
    return 0;
}
