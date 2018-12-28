#include<iostream>

using namespace std;

int main()
{
int quarter = 0,dime = 0,nickel = 0,penny = 0;

int coins;
cout<<"Enter the amount:";
cin>>coins;

while(coins>0)
{
        if(coins<5)
        {
                penny++;
                coins=coins-1;
        }
        else if((coins>=5)&&(coins<10))
        {
                nickel++;
                coins=coins-5;
        }
        else if((coins>=10)&&(coins<25))
        {
                dime++;
                coins=coins-10;
        }
        else if(coins>=25)
        {
                quarter++;
                coins=coins-25;
        }

}
cout<<" No of quarters = "<<quarter<<"\n No of  dimes = "<< dime<<"\n No of nickels = "<<nickel<<"\n No of penny = "<<penny<<"\n";

return 0;

}
