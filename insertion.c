                                            /*RISHABH JAIN*/
                /*ARRANGE THE ELEMENTS OF THE ARRAY IN PARTICULAR ORDER(ASCENDING ORDER)USING INSERTION SORT*/

#include<stdio.h>                                                               //HEADER FILE
#define max 100

void insert(int [],int);                                                        //FUNCTION DECLARATIONS
void insertion(int [],int);
void display(int [],int);

int main()                                                                      //MAIN FUNCTION
{
    int arr[max],lim;
    printf("PLEASE ENTER LIMIT OF ARRAY < %d\t",max);
    scanf("%d",&lim);
    insert(arr,lim);                                                            //FUNCTION CALL TO INSERT THE ELEMENT
    printf("ELEMENTS BEFORE SORTING\n");
    display(arr,lim);                                                           //FUNCTION CALL TO DISPLAY THE ELEMENTS
    insertion(arr,lim);                                                         //FUNCTION CALL TO SORT THE ELEMENTS
    printf("\nELEMENTS AFTER SORTING\n");
    display(arr,lim);                                                           //FUNCTION CALL TO DISPALY THE ELEMENTS
    return ;

}

void insert(int arr[],int n)                                                     //INSERT FUNCTION
{
    int i;
    printf("PLEASE ENTER ELEMENTS\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void insertion(int arr[],int n)                                                   //FUNCTION TO SORT THE ELEMENTS
{
        int i,j,temp;
        for(i=1;i<n;i++)
        {
            temp=arr[i];
            j=i-1;
            while(j>=0&&temp<arr[j])
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=temp;
        }
}

void display(int arr[],int n)                                                       //FUNCTION TO DISPLAY THE ELEMENTS
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
