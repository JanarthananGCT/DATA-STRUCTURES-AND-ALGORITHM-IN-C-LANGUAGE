#include<stdio.h>
int arr[100];
int rear=-1,front=-1;
void enqueue()
{
 int val;
 if(rear==100)
 printf("Overflow");
 else if(front==-1)
 {
 printf("Enter first value in queue: ");
 scanf("%d",&val);
 rear=0;
 front=0;
 arr[rear]=val;
 }
 else
 {
 printf("Enter value: ");
 scanf("%d",&val);
 rear++;
 arr[rear]=val;
 }
}
void dequeue()
{
 if(front == -1)
printf("Queue is empty");
else
{
 printf("Deleted element is: %d",arr[front]);
 front++;
}
}
void display()
{
    int i;
 printf("arrray elements arre: ");
 for(i=front;i<=rear;i++)
 {
 printf(" %d ",arr[i]);
 }
}
void main()
{
 int y;
 do
 {
 printf("\n1.Enqueue\n2.dequeue\n3.Display\n4.Exit\nEnter your choice ");
 scanf("%d",&y);
 switch(y)
 {
 case 1:
 enqueue();
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 break;
 default:
 printf("Incorrect input");
 }
 }while(y!=4);
}