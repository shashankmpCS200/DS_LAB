#include<stdlib.h>
#include<malloc.h>

void create();
void display();
void insert_front();
void insert_end();
void insert_val();

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *start=NULL;

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create  2.Insert irst  3.Insert end 4.Insert after 5.display 6.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;

        case 2:
            insert_front();
            break;
        case 3:
            insert_end();
            break;
        case 4: insert_val();
            break;
             case 5: display();
            break;
        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}

void create()
{
    int c;
    node *new,*curr;
    start=(node *) malloc(sizeof(node));
    curr=start;
    printf("Enter element\n");
    scanf("%d",&start->data);
    while(1)
    {
        printf("Do you want to add another element(1/0)\n");
        scanf("%d",&c);
        if(c==1)
        {
            new=(node *) malloc(sizeof(node));
            printf("Enter element\n");
            scanf("%d",&new->data);
            curr->link = new;
            curr=new;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}

void insert_front(){
    node *temp,*mew;
    mew = (node *) malloc(sizeof(node));
    temp = start;
    printf("enter element value\n");
    scanf("%d",&mew->data);
    mew->link = start;
    start = mew;
}
void insert_end(){
    node *new,*temp;
    new = (node *) malloc(sizeof(node));
    temp = start;
    printf("enter element value\n");
    scanf("%d",&new->data);
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = new;
    new->link = NULL;
}
void insert_val(){
        node *new,*ptr,*prevptr;
        int val;
    new = (node *) malloc(sizeof(node));
    ptr = start;
    prevptr = start;
    printf("enter element value\n");
    scanf("%d",&new->data);
    printf("enter value in between where to enter\n");
    scanf("%d",&val);
    int i=1;
    while(i<val){
        prevptr = ptr;
        ptr = ptr->link;
        i++;
    }
    prevptr->link = new;
    new->link = ptr;
}void display()
{
    node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    else{
               printf("Linked list elements are:\n");
    while(temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp = temp->link;
    }
    }
}
