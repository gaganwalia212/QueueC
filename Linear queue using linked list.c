#include <stdio.h>
#include <stdlib.h>
//linear list using linked list..
//here we don't face the condition of overflow
//also absurd conditions of linear list using array are all dealt with
struct Node
{
    int info;
    struct Node* next;
};
typedef struct Node* nodeptr;

//generating node on heap
nodeptr getnode()
{
    nodeptr p=(nodeptr)malloc(sizeof(struct Node));
    return p;
}

//deallocating node on heap
void freenode(nodeptr p)
{
    free(p);
}

struct Queue
{
    //now we have pointers to two ends
    //no need of array since data is now stored dynamically on heap
    nodeptr front;
    nodeptr rear;
};

void insert(struct Queue*q,int x)//pass by address since you might need to change values
{
    nodeptr p=getnode();
    p->info=x;
    p->next=0;
    if(q->front==0)//no node is present
    {
        q->front=q->rear=p;
    }
    else//queue is not empty so insert at last
    {
        q->rear->next=p;
        q->rear=p;
    }
}

int delete(struct Queue*q)
{
    if(q->front==0)//if queue is empty
    {
        printf("Underflow\n");
        return -1;
    }

    nodeptr p=q->front;
    q->front=q->front->next;
    int x=p->info;
    freenode(p);
    return x;
}

void display(struct Queue *q)
{
    printf("[ ");
    nodeptr p=q->front;
    while(p)
    {
        printf("%d ",p->info);
        p=p->next;
    }
    printf("]\n");
}

int is_empty(struct Queue* q)
{
    if(q->front ==0) return 1;
    else return 0;
}
int main()
{
   struct Queue q;
    q.front=q.rear=0;//initializing Node pointers
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
