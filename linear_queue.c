#include<stdio.h>
#include<stdlib.h>
#define size 3
int front=-1,rear=-1,item,del;
int q[size];

void insert();
int delete();
void display();

int main(){
    int choice;
    while(1){
    printf("Choose the operation\n");
    printf("1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
    scanf("%d",&choice);

    switch(choice){
    case 1:
            insert();
            break;
    case 2:
            del=delete();
            printf("The deleted element is %d\n",del);
            break;
    case 3:
            display();
            break;
    case 4:
            exit(0);
    default:
            printf("Invalid inputs\n");
    }
    }
}

void insert(){
    if(rear==size-1){
        printf("Queue is full\n");
        return;
    }
    if(front==-1&&rear==-1){
        front=0;
    }
        rear++;
        printf("Enter element: ");
        scanf("%d",&item);
        q[rear]=item;

}


int delete(){
    if(front==-1&&rear==-1){
        printf("Queue is empty so\n");
        return -1;
    }
    int d=q[front];
    if(front==rear){
        front=-1;rear=-1;
    }
    else{
        front++;
    }
    return d;
}

void display(){
    if(front==-1&&rear==-1){
        printf("Queue is full\n");
        return;
    }
    else{
        printf("Queue elements are: ");
        for(int i=front;i<=rear;i++){
            printf("%d ",q[i]);
        }
    }
}
