#include<fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int dp[1025][1025],a[1025],b[1025],s[1025];
int main()
{
    int n,m,i,j,c=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
     cin>>a[i];
    for(i=1;i<=m;i++)
     cin>>b[i];
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
      {if(a[i]==b[j])
        dp[i][j]=1+dp[i-1][j-1];
       else
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
      }
    i=n;
    j=m;
    while(dp[i][j]>0)
        if(a[i]==b[j])
        {
            c++;
            s[c]=a[i];
            i--;
            j--;
        }
        else
         if(dp[i][j-1]>dp[i-1][j])
          j--;
          else
           i--;
    cout<<c<<'\n';
    for(i=c;i>=1;i--)
     cout<<s[i]<<" ";

     

}