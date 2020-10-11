#include <stdio.h>
#include <stdlib.h>
//ascending priority queue using linear queue
//don't need a circular queue
//store in any form
//deletion -- shifting
//smallest element will be shifted
#define maxsize 5
struct Queue
{
    //you can store only maxsize-1  elements
    int arr[maxsize];
    int rear;// initially -1
    //you don't require a front here
};

int is_empty(struct Queue* q)
{
    if(q->rear==-1)return 1;
    else return 0;
}

int is_full(struct Queue*q)
{
    if(q->rear==maxsize-1)return 1;
    else return 0;


}

void display(struct Queue * q)
{
    printf("[ ");
 for(int i=0;i<=q->rear;i++)
    printf("%d ",q->arr[i]);
    printf("]\n");
}

void insert(struct Queue* q,int x)
{
    if(is_full(q)==1)//send address
    {
        printf("Overflow\n");
        return;
    }

    q->rear=(q->rear+1);
    q->arr[q->rear]=x;
}

int delete(struct Queue* q)
{
    if(is_empty(q)==1)//send address
    {
        printf("Underflow\n");
        return -1;
    }
   int min_value=10000;
   int index=-1;
   for(int i=0;i<=q->rear;i++)
   {
       if(q->arr[i]<min_value)
       {
           min_value=q->arr[i];
           index=i;
       }
   }
   for(int k=index;k<q->rear;k++)
    q->arr[k]=q->arr[k+1];
   q->rear--;
   return min_value;
}
int main()
{
     struct Queue q;
    q.rear=-1;//initializing index pointers
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
