
#include <fstream>
#include <vector>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m;
vector<int> A,B;
int dp[1025][1025];
void afisare(int n,int m)
{
    if(!n || !m)
       return;
    if(A[n-1]==B[m-1])
    {
        afisare(n-1,m-1);
        cout<<A[n-1]<<" ";
    }
    else
      if(dp[n-1][m]>dp[n][m-1])
         afisare(n-1,m);
      else
         afisare(n,m-1);
}
int main()
{
    cin>>n>>m;
    A.resize(n);
    B.resize(m);
    for(int i=0;i<n;i++)
      cin>>A[i];
    for(int i=0;i<m;i++)
      cin>>B[i];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
       if(A[i-1]==B[j-1])
          dp[i][j]=dp[i-1][j-1]+1;
       else
         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    cout<<dp[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
