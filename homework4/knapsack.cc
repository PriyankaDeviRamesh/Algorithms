#include<iostream>

using namespace std;

int max(int x, int y){
	if(x>y)
	{
		return x;
	}
	else{
		return y;
	}
}
int main()
{
	int total_items, knapsackcapacity;
	int table[20][20],Elements[10],Weight[10],Value[10];

	cout<<"Enter total_items:\n";
	cin>>total_items;

	cout<<"Enter knapsack's capacity\n";
	cin>>knapsackcapacity;

	for(int i=1;i<total_items+1;i++)
	{
		cout<<"Enter weight of item\n";
		cin>>Weight[i];
		cout<<"Enter value of item\n";
		cin>>Value[i];
	}

	for(int i=0;i<knapsackcapacity+1;i++)
	table[0][i]=0;

	for(int j=0;j<knapsackcapacity+1;j++)
	{
        	for(int i=1;i<total_items+1;i++)
        	{
        		if(j==0)
        		table[i][0]=0;
                	if(j!=0)
                	{
                        	if((j-Weight[i])>=0)
                        	table[i][j]=max(Value[i]+table[i-1][j-Weight[i]],table[i-1][j]);
                        else
                        	table[i][j]=table[i-1][j];

                }
        }
}
	cout<<"Knapsack Table";
	for(int i=1;i<total_items+1;i++)
	{	
		cout<<"\n";
        	for(int j=0;j<knapsackcapacity+1;j++)
        	{
        		cout<<"\t"<<table[i][j];
        	}
	}

	int i,k;
	i=total_items;
	k=knapsackcapacity;

	cout<<"\nPath Tracing\n";

	while((i>0)&&(k>0))
	{
    		if(table[i][k]!=table[i-1][k])
        	{
                	cout<<"Comparing "<<table[i][k]<<" and "<<" "<<table[i-1][k];
                	cout<<"\nItem "<<i<<" is included\n";
                	k=k-Weight[i];
                	i=i-1;
       	 	}
        	else
        	{
                	cout<<"Comparing "<<table[i][k]<<" and "<<table[i-1][k];
                	i=i-1;
        	}
	}

return 0;

}


