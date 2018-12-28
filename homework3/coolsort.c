
#include <stdio.h>
int main()
{
  int k, num, array[20], i, j, key, H_Value;

  printf("Enter number of elements in main array\n");
  scanf("%d", &num);

  printf("Enter the %d elements of main array\n", num);

  for (i = 0; i < num; i++) {
    scanf("%d", &array[i]);
  }

printf("Enter the H values");

for(k=0;k<3;k++)
{
   scanf("%d",&H_Value);
   if(k==0)
   {
    if(H_Value>num)
    { 
        printf("Enter first element of H_array less than the length of main array\n");
        break;
     }
  }
     if(k==2)
     {
        if(H_Value!=1)
        { 
            printf("Enter last element of H_array to be 1\n");
            break;;
        }
}

   for (i = 0; i < num; i=i+H_Value)
   {
       key = array[i];
       j = i-1;

       while (j >= 0 && array[j] > key)
       {
           array[j+1] = array[j];
           j = j-1;
       }
       array[j+1] = key;
   }
}
for (i=0; i < num; i++)
       printf("%d ", array[i]);
  return 0;
}


