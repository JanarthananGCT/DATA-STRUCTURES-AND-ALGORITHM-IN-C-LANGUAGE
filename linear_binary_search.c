#include<stdio.h>
int linearsearch(int ar[],int size,int value)
{
 int i,flag=0;
 for(i=0;i<size;i++)
 {
 if(ar[i]==value)
 {
 printf("Array element found in %d position\n",i+1);
 flag=1;
 }
 }
 if(flag==0)
 return -1;
 else
 return 0;
}
int binarysearch(int arr[],int size,int value)
{
 int l=0,r=size;
 while (l <= r)
 {
 int m = l + (r - l) / 2;
 // Check if x is present at mid
 if (arr[m] == value)
 return m;
 // If x greater, ignore left half
 if (arr[m] < value)
 l = m + 1;
 // If x is smaller, ignore right half
 else
 r = m - 1;
 }
 return -1;
}
void main1()
{
    int i;
 int array[100];
 int size,ch,value,res;
 printf("Enter number of elements: ");
 scanf("%d",&size);
 printf("Enter array elements: ");
 for(i=0;i<size;i++)
 scanf("%d",&array[i]);
 printf("1. Binary search(sorted array) \n2.Linear search \nEnter your choice: ");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("Enter search value: ");
 scanf("%d",&value);
 res=binarysearch(array,size,value);
 if(res!=-1)
 printf("The element is present in position %d",res+1);
 break;
 case 2:
 printf("Enter search value: ");
 scanf("%d",&value);
 res=linearsearch(array,size,value);
 break;
 default:
 printf("Wrong input ");
 }
 if(res==-1)
 {
 printf("Given value is not in the array ");
 }
}
void main(){
    int i=0;
    while(i<3){
        main1();
        i++;
    }
    
}