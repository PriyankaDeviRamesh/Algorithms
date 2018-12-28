#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

void lcs( char *str1, char *str2, int len_str1, int len_str2 ){
   int table[len_str1+1][len_str2+1];
   for (int i=0; i<=len_str1; i++){
     for (int j=0; j<=len_str2; j++){
       if (i == 0 || j == 0)
         table[i][j] = 0;
       else if (str1[i-1] == str2[j-1])
         table[i][j] = table[i-1][j-1] + 1;
       else
         table[i][j] = max(table[i-1][j], table[i][j-1]);
     }
   }

   int m = table[len_str1][len_str2];

   char lcs[m+1];
   lcs[m] = '\0'; 

   int i = len_str1, j = len_str2;
   while (i > 0 && j > 0){
      if (str1[i-1] == str2[j-1]){
          lcs[m-1] = str1[i-1]; // Put current character in result
          i--; 
	  j--; 
          m--;  }

      else if (table[i-1][j] > table[i][j-1]){
         i--;}
      else{
         j--;}
   }

cout<<"\n\n";

	for(int i=0;i<=len_str1;i++){
		for(int j=0;j<=len_str2;j++){
			cout<<" "<<table[i][j];}
	cout<<"\n";}

   cout << "Least Common Subsequence  of given strings is" << lcs;
}
int main(){
  char str1[50];
  char str2[50];
  cout<<"Enter the two strings";
	cin>>str1;
	cin>>str2;
  int len_str1 = strlen(str1);
  int len_str2 = strlen(str2);
  lcs(str1, str2, len_str1, len_str2);
  return 0;
}

