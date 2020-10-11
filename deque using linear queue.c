#include <stdio.h>
#include <stdlib.h>
//array implementation of deque using linear queue array implementation
#define maxsize 5
struct Queue
{
    int arr[maxsize];
    int front;//initialize to -1
    int rear;//initialize to -1

};
void insert_front(struct Queue* q,int x)
{
    if(q->front==-1)
    {
        printf("Not possible to insert at front\n");
        return;
    }
    q->arr[q->front]=x;
    q->front--;
}

void insert_rear(struct Queue * q,int x)
{
    if(q->rear==maxsize-1)
    {
        printf("Overflow\n");
        return;
    }
    q->rear++;
    q->arr[q->rear]=x;
}

int delete_front(struct Queue*q)
{
    if(q->front==q->rear)
    {
        printf("Underflow\n");
        return -1;
    }
    int x=q->arr[++q->front];
    if(q->front==q->rear)q->front=q->rear=-1;//re-initializing
    return x;
}
int delete_rear(struct Queue * q)
{
    if(q->front==q->rear)
    {
        printf("Underflow\n");
        return -1;
    }
    int x=q->arr[q->rear];
    q->rear--;
    if(q->front==q->rear)q->front=q->rear=-1;//re-initializing
    return x;
}

int is_empty(struct Queue* q)
{
    return (q->front==q->rear);
}

int is_full(struct Queue*q)
{
    return q->rear==maxsize-1;
}

void display(struct Queue * q)
{
    printf("[ ");
    for(int i=q->front+1;i<=q->rear;i++)
    {
        printf("%d ",q->arr[i]);

    }
    printf("]\n");
}
int main()
{ struct Queue q;
    q.front=q.rear=-1;//initializing index pointers
    int input;
    do
    {
        printf("\n-------------------------\n");
       printf("1-Insert Front\n");
       printf("2-Insert Rear\n");
       printf("3-Delete Front\n");
       printf("4-Delete Rear\n");
       printf("5-Is Empty\n");
       printf("6-Is Full\n");
       printf("7-Display\n");
       printf("Any other number for exit\n");
       scanf("%d",&input);
       printf("\n-------------------------\n");
       switch (input)
       {
       case 1:
        {
            int x;
            printf("Enter element to be inserted at front:");
            scanf("%d",&x);
            insert_front(&q,x);
            break;
        }
       case 2:
        {
            int x;
            printf("Enter element to be inserted at rear:");
            scanf("%d",&x);
            insert_rear(&q,x);
            break;
        }
       case 3:
        {
            int x;
            x=delete_front(&q);
            if(x!=-1)
            printf("%d deleted from front\n",x);
                break;
        }
       case 4:
        {
            int x;
            x=delete_rear(&q);
            if(x!=-1)
            printf("%d deleted from front\n",x);
                break;
        }
       case 5:
        {
            if(is_empty(&q)==1)
                printf("The queue is empty\n");
            else printf("The queue is not empty\n");

            break;

        }
       case 6:
        {
           if(is_full(&q)==1)
                printf("The queue is full\n");
            else printf("The queue is not full\n");

            break;
        }
       case 7:
        {
            display(&q);
            break;

        }
        default:break;
       }
    }
    while(input>=1&&input<=7);
    printf("\n----CLOSING PROGRAM---\n");

    return 0;
}
