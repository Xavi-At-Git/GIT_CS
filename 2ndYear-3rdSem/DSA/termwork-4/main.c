#include <stdio.h>
#include <stdlib.h>


#define size 3 

int queue[size];
int front = -1 ; 
int rear = -1 ;

void enqueue(){
  if(rear==size-1){
    printf("\t Queue Overflow \n");
  }else{
    int element;
    printf("enter element : ");
    scanf("%d",&element);
    if(front == -1 ) front = 0;
    queue[++rear]=element ;
    printf("\t %d inserted in Queue \n",element);
  }
}

void dequeue(){
  if (front > rear){
    printf("Queue underflow ");
    return ;
  }else{
    printf("\t deleted element is :%d \n",queue[front++]);  
  }
}

void display(){
  if (front>rear || front ==-1){
    printf("stack empty.");
    return;
  }else{
    printf("\t Queue elements are : ");
    for(int i = front ; front <= rear ; front ++){
      printf("%d ",queue[front]);
    }printf(". \n");
  }
}


int main(){
  int choice = 0 ;
  int element ;

  while (choice!=4){
    printf("\n1.Enqueue\t2.Dequeue\n3.Display\t4.Exit\n");
		printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4 :
        printf("\n Exiting .... \n ");
        exit(1);
        break;
      default:
        printf("\n invalid option try again. \n");
        break;

    }
  }
}