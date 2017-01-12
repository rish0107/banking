                                            /*RISHABH JAIN*/
                /*ARRANGE THE ELEMENTS OF THE ARRAY IN PARTICULAR ORDER(ASCENDING ORDER)USING SELECTION SORT*/

#include<stdio.h>                                                           //HEADER FILE
#define max 100

void insert(int [],int);                                                    //FUNCTION DECLARATIONS
void selection(int [],int);
void display(int [],int);

int main()                                                                  //MAIN FUNCTION
{
    int arr[max],lim;
    printf("PLEASE ENTER LIMIT OF ARRAY < %d\t",max);
    scanf("%d",&lim);
    insert(arr,lim);                                                        //FUNCTION CALL TO INSERT THE ELEMENTS
    printf("ELEMENTS BEFORE SORTING\n");
    display(arr,lim);                                                       //FUNCTION CALL TO DISPLAY THE ELEMENTS
    selection(arr,lim);                                                     //FUNCTION CALL TO SORT THE ELEMENTS
    printf("\nELEMENTS AFTER SORTING\n");
    display(arr,lim);                                                       //FUNCTION CALL TO DISPALY THE ELEMENTS
    return ;

}

void insert(int arr[],int n)                                                //INSERT FUNCTION
{
    int i;
    printf("PLEASE ENTER ELEMENTS\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);                                                //INSERT ELEMENT IN THE ARRAY
    }
}

void selection(int arr[],int n)                                             //FUNCTION TO SORT THE ARRAY
{
    int min,pos,i,j;
    for(i=0;i<n-1;i++)
    {
        min=arr[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                pos=j;
            }
        }
        if(i!=pos)
        {
            arr[pos]=arr[i];
            arr[i]=min;
        }
    }
}

void display(int arr[],int n)                                               //FUNCTION TO DISPLAY THE ELEMENTS
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
