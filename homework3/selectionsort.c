#include <stdio.h>
 
void swap(int *x , int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void selectionSort(int array[], int num)
{
    int i, j, min;
 
   
    for (i = 0; i < num; i++)
    {
    
        min = i;
        for (j = i+1; j < num; j++)
          if (array[j] < array[min])
            min = j;
 
        swap(&array[min], &array[i]);
        printf("%d ", array[i]);

    }
}
 void selectionsort(int array[], int num, int k)
{
	int i, j, min;
 
    for (i = 0; i < k; i++)
    {
        min = i;
        for (j = i+1; j < num; j++)
          if (array[j] < array[min])
            min = j;
 
        swap(&array[min], &array[i]);
        printf("%d ", array[i]);

    } 

} 
int  median(int array[], int num)
{
    int mid;
    if(num%2==0) {
          mid=num/2;
                return (array[mid]+array[mid+1])/2;
                
        }
        else
        {
                mid=num/2;
                return array[mid];
               
        }
}
int main()
{
  
    int array[50], num, k;
    printf("Enter Number of Elements");
    scanf("%d", &num);
    printf("\nEnter the elements to be sorted");
    for(int i=0; i<num; i++)
    {
        scanf("%d", &array[i]);	
    } 
    printf("\nSorted Array:");
    selectionSort(array, num);
    printf("\nEnter the k value:");
    scanf("%d", &k);
    printf("\nk Sorted elements are:");
    selectionsort(array,num,k);
    int mvalue = median(array, num);
    printf("\nMedian Value is: %d\n", mvalue);
    return 0;
}

