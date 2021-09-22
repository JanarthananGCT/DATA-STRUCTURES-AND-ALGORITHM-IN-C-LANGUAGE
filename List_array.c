#include <stdio.h>
void printarr(int Arr[],int t);
int main() {

    int n,x,y,z,pos,m,o,i ,w ;
    int arr[100]={0};
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        printf("arr[%d] = ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("1: Travers and search based on position\n");
    printf("2: Travers and search based on key values\n");
    printf("3: Insertion\n");
    printf("4: Deletion\n");
    scanf("%d",&y);

    if(y==1)
    {
        printf("Travers and search based on position\n");
        printf("Enter the elemental position :");
        scanf("%d",&m);
        printf("arr[%d]= %d",m ,arr[m-1]);
    }
    if(y==2)
    {
        printf("Travers and search based on key values\n");
        printf("Enter the key value:");
        scanf("%d",&o);
        for(i=0;i<n;i++)
        {
            if(arr[i]==o)
            {
                printf("%d is in %d position in the array\n ",(o),(i+1));
                break;
            }
        }
    }
    if(y==3)
    {
        printf("Insertion\n");
        printf("where to insert element");
        scanf("%d",&x);
        pos=x-1;
        printf("which element to insert");
        scanf("%d",&z);
        n++;
        for(w =n;w>=pos;w--)
        {
            arr[w]=arr[w-1];
        }
        arr[pos]=z;
        printarr(arr,n);
    }
    else if(y==4)
    {
        printf("Deletion\n");
        printf("Where to delete the element");
        scanf("%d",&x);
        pos=x-1;
        n--;
        for(w=pos ;w<=n ; w++)
        {
            arr[w]=arr[w+1];
        }
        printarr(arr,n);
    }


}
void printarr(int Arr[],int t)
{
    int j;
    for(j=0;j<t;j++)
    {
        printf("arr[%d] =%d\n",j+1, Arr[j]);
    }
}
