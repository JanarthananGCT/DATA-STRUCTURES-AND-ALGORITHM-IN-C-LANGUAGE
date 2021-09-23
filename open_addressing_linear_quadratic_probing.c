//linear probing
#include<stdio.h>

int n;
int r=0;j=0;
int m;
void insertLinear(int arr[])
{
    int temp,k,i;
        printf("Enter element: ");
        scanf("%d",&temp);
        k=temp%n;
        if(check(arr,k)==0)
            arr[k]=temp;
        else
        {
            i=k+1;
            while(i!=k)
            {
                if(check(arr,i)==0)
                {
                 arr[i]=temp;
                 break;
                }
                  i++;
                if(i==n)
                    i=0;


            }
        }


}
void insertquadratic(int arr[])
{
    int temp,k,i=1,j=1;
//    if(r<m)
//    {
        printf("Enter element: ");
        scanf("%d",&temp);
        k=temp%m;
        if(check(arr,k)==0)
            arr[k]=temp;
        else
        {
            i=k+j*j;
            if(i>=m)
                    printf("Out of bound");
            while(i<m)
            {

                if(check(arr,i)==0)
                {
                 arr[i]=temp;
                 break;
                }
                j++;
                i=k+j*j;
            }
            if(i>=m)
                    printf("Out of bound");
        }

//    }
//    else
//        printf("The hash table is full");

}
int check(int arr[],int val)
{
    int m;
    if(arr[val]!=NULL)
        return 1;
    for(int i=0;i<n;i++)
    {
        if(i==0&&arr[0]==0)
            return 0;
        if((arr[i]%n)==(val%n))
            return 1;
    }
    return 0;
}
void main()
{
    int c;
    start:
    printf("1.Linear probing\n2.Quadratic probing\nChoice: ");
    scanf("%d",&c);
if(c==1)
{
    int choice;
    printf("Enter number of elements in hash table: ");
    scanf("%d",&n);
    int arr[100]={NULL};
    do{

    printf("\n1.Insert\t\t\t2.Display\n3.Exit\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                insertLinear(arr);
                break;
        case 2:
            for(int i=0;i<n;i++)
            {
                printf("%d position - %d ; ",i,arr[i]);
                if(i%5==0&&i!=0)
                    printf("\n");
            }
            break;
        case 3:
            break;
        default:
                printf("Wrong input try again.");
            break;
    }
    }while(choice!=3);
}
else if(c==2)
{
    int choice;
    printf("Enter number of elements in hash table: ");
    scanf("%d",&m);
    int arr[100]={NULL};
    do{
    printf("\n1.Insert\n2.Display\n3.Exit\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            insertquadratic(arr);
            break;
        case 2:
            for(int i=0;i<m;i++)
            {
                printf("%d position - %d ; ",i,arr[i]);
                if(i%5==0&&i!=0)
                    printf("\n");
            }
            break;
        case 3:
            break;
        default:
                printf("Wrong input try again.");
            break;
    }
    }while(choice!=3);
}
else
{
      printf("Wrong input");
    goto start;
}

}