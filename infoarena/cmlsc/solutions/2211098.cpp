#include <iostream>
#include <fstream>

using namespace std;
const int MAX=1024;

int a[MAX],na,nb, b[MAX], dp[MAX][MAX];

int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin>>na>>nb;
    for(int i=na;i>=1;i--) cin>>a[i];
    for(int i=nb;i>=1;i--) cin>>b[i];

    for(int i=1;i<=na;i++)
       for(int j=1;j<=nb;j++)
       {
           if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];
           else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
       }


       cout<<dp[na][nb]<<'\n';

       while(dp[na][nb]>0)
       {
           if(a[na]==b[nb])
           {
               cout<<a[na]<<" ";
               na--;
               nb--;
           }

           else if(dp[na][nb]==dp[na-1][nb]) na--;
           else nb--;
       }
    return 0;
}
