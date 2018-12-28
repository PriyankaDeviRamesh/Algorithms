#include <stdio.h>
 
int main()
{
   int i, first, last, middle, num, array[100];
 
   printf("Enter number of elements\n");
   scanf("%d",&num);
 
   printf("Enter %d integers\n", num);
 
   for (i = 0; i < num; i++){
      scanf("%d",&array[i]);
       }
   first = 0;
   last = num - 1;
   middle = (first+last)/2;
 
   while (first <= last) {
      if (array[middle] == middle){
          printf(" The Array has an index equal to the array element");
          break;
       }
	else if(array[middle] < middle)
             first = middle + 1;      

        else 	
	last = middle - 1;   
     
      middle = (first + last)/2;
   
}
   if (first > last)
      printf(" The Array doesnt have an index equal to the array element");  

   return 0;   
}
