#include <stdio.h>
#include <stdlib.h>
//GAGAN WALIA
//Queue using array
#define maxsize 100//maximum number of element in a queue
struct Queue {
int arr[maxsize];//array of 100 element
int rear;//insertion after rear index
int front;//deletion after front index
};

int is_empty(struct Queue* q)
{
    if(q->rear==q->front)
        return 1;
    else return 0;
}

void insert(struct Queue * q,int x)
{
    if(q->rear==maxsize-1)
    {
        printf("Overflow\n");
        return;
    }
    q->arr[++q->rear]=x;
}

int delete(struct Queue*q)
{
    if(q->rear==q->front)
    {
        printf("Underflow\n");
        return -1;
    }
    int x=q->arr[++q->front];
    //this is optional..(will make the code implementation better)
    if(q->front==q->rear)
    q->front=q->rear=-1;//re-initialize to empty queue

    return x;
}

void display(struct Queue * q)
{
    printf("[ ");
    for(int i=q->front+1;i<=q->rear;i++)
        printf("%d ",q->arr[i]);
    printf("]\n");
}
int main()
{
    struct Queue q;
    q.front=q.rear=-1;//initializing index pointers
    int input;
    do
    {
        printf("\n-------------------------\n");
       printf("1-Insert\n");
       printf("2-Delete\n");
       printf("3-Is Empty\n");
       printf("4-Display\n");
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
            display(&q);
            break;

        }
        default:break;
       }
    }
    while(input==1||input==2||input==3||input==4);
    printf("\n----CLOSING PROGRAM---\n");

    return 0;
}
