#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[1035][1035];
int s1[1025],s2[1025];
int aux[1026];
int k;
int l1,l2;
int main() {
	cin>>l1>>l2;
	for(int i=1;i<=l1;i++)cin>>s1[i];
	for(int i=1;i<=l2;i++)cin>>s2[i];
	for(int i=1;i<=l1;i++)
	  {
	  	for(int j=1;j<=l2;j++)
	  	{
	  		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	  		if(s1[i]==s2[j])
	  		{
	  			dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
	  		}
	  	}
	  }
 
 
 
	  cout<<dp[l1][l2]<<"/n";
       for(int i=l1,j=l2,k=dp[l1][l2];i>0 && j>0;)
       {
       	if(s1[i]==s2[j])
	      	{  aux[k]=s1[i];
	      	k--;
	      	i--;
	      	j--;
	        }
	        if(dp[i][j-1]>dp[i-1][j-1])
	        j--;
	        else i--;
       }
       for(int i=1;i<=dp[l1][l2];i++)
       {
       	cout<<aux[i]<<" ";
       }
 
 
 
	return 0;
}