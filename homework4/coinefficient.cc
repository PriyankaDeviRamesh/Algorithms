#include<iostream>
using namespace std;
int changecoin(int total_amount);

int main()
{
int total_amount;
cout<<"Enter amount to be changed\n";
cin>>total_amount;
changecoin(total_amount);
cout<<"\n\n";
return 0;
}

int changecoin(int total_amount)
{
int n,coin[20],coincount=0,currentcoin;

printf("Enter total no of coin denominations\n");
cin>>n;
cout<<"Enter the coin denominations\n";
for(int i=0;i<n;i++)
cin>>coin[i];

  for (int i = 0; i < n-1; i++)
       for (int j = 0; j < n-i-1; j++)
           if (coin[j] > coin[j+1])
           {
                int temp = coin[j];
                coin[j] = coin[j+1];
                coin[j+1] = temp;
           }

cout<<"coin selected";
while(total_amount>0)
{
        for(int i=n;i>0;i--)
        {
                currentcoin=coin[i-1];

                if(total_amount>=currentcoin)
                {
                        cout<<" "<<currentcoin;
                        coincount++;
                        total_amount=total_amount-currentcoin;
                        break;
                }
        }
}
printf("\n\nNo of coins : %d",coincount);
}

