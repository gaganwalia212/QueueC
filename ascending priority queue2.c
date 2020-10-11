#include <stdio.h>
#include <stdlib.h>
// Ascending Priority Queue using circular queue
//we will store elements in sorted form
//smallest element will be dequeued
#define maxsize 5
struct Queue
{
    //you can store only maxsize-1  elements
    int arr[maxsize];
    int rear;//0 initially
    int front;//0 initially
};

int is_empty(struct Queue* q)
{
    if(q->front==q->rear)return 1;
    else return 0;
}

int is_full(struct Queue*q)
{
    if(q->front==(q->rear+1)%maxsize)return 1;
    else return 0;

//    //this can also be written
//    if(q->rear==maxsize-1&&q->front==0)return 1;
//    else if(q->front==q->rear+1) return 1;
//    else return 0;
}

void display(struct Queue * q)
{
    printf("[ ");
    int i=(q->front+1)%maxsize;
    if(q->front !=q->rear)//if list is not empty
    {
        while(i!=(q->rear+1)%maxsize)
        {
            printf("%d ",q->arr[i]);
            i=(i+1)%maxsize;
        }
    }
    printf("]\n");
}

void insert(struct Queue* q,int x)
{
    if(is_full(q)==1)//send address
    {
        printf("Overflow\n");
        return;
    }
    int i;
for( i=(q->front+1)%maxsize;i!=(q->rear+1)%maxsize;i=(i+1)%maxsize)
{
        if(q->arr[i]>x)
            break;
}

if(i==(q->rear+1)%maxsize)
{
    q->rear=(q->rear+1)%maxsize;
    q->arr[q->rear]=x;
    return;
}

//shifting
for(int k=(q->rear+1)%maxsize;k!=i;k=(k+maxsize-1)%maxsize)
{
    q->arr[k]=q->arr[(k-1+maxsize)%maxsize];
}
q->arr[i]=x;
q->rear=(q->rear+1)%maxsize;
}

int delete(struct Queue* q)
{
    if(is_empty(q)==1)//send address
    {
        printf("Underflow\n");
        return -1;
    }
    q->front=(q->front+1)%maxsize;
    return q->arr[q->front];
}
int main()
{
     struct Queue q;
    q.front=q.rear=0;//initializing index pointers
    int input;
    do
    {
        printf("\n-------------------------\n");
       printf("1-Insert\n");
       printf("2-Delete\n");
       printf("3-Is Empty\n");
       printf("4-Is Full\n");
       printf("5-Display\n");
       printf("Any other number for exit\n");
       scanf("%d",&input);
       printf("\n-------------------------\n");
       switch (input)
       {
       case 1:
        {
            int x;
            printf("Enter element to be inserted:");
            scanf("%d",&x);
            insert(&q,x);
            break;
        }
       case 2:
        {
            int x;
            x=delete(&q);
            if(x!=-1)
            printf("%d deleted\n",x);
                break;
        }
       case 3:
        {
            if(is_empty(&q)==1)
                printf("The queue is empty\n");
            else printf("The queue is not empty\n");

            break;

        }
       case 4:
        {
            if(is_full(&q)==1)
                printf("The queue is full\n");
            else printf("The queue is not full\n");

            break;
        }
       case 5:
        {
            display(&q);
            break;

        }
        default:break;
       }
    }
    while(input==1||input==2||input==3||input==4||input==5);
    printf("\n----CLOSING PROGRAM---\n");

    return 0;
}
