/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[1025][1025];
int a[1024];
int b[1024];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
       cin>>a[i];
    for(int i=0;i<m;i++)
       cin>>b[i];
    for(int i=n-1;i>=0;i--)
       for(int j=m-1;j>=0;j--)
             if(a[i]==b[j])
                 dp[i][j]=dp[i+1][j+1]+1;
              else
                 dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
    cout<<dp[0][0]<<'\n';
    int l=dp[0][0],i=0,j=0;
    while(l)
    {
        if(a[i]==b[j])
          {
              cout<<a[i]<<" ";
              i++;
              j++;
              l--;
          }
        else
          if(dp[i+1][j]>=dp[i][j+1])
             i++;
        else
           j++;
    }
    return 0;
}
