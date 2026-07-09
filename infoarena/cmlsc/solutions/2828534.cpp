#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,v[1025],w[1025],dp[1025][1025],i,j,mx,k,st[1025];
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v[i];
    for(i=1;i<=m;i++)
        cin>>w[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(v[i]==w[j])dp[i][j]=dp[i-1][j];
    }
     mx=dp[n][m];
    i=n;
    j=m;
    fout<<mx<<"\n";
    while(mx)
    {
        if(v[i]==w[j])
        {
            k++;
            st[k]=v[i];
            mx--;
            i--;
            j--;
        }
        else if(mx==dp[i-1][j]) i--;
        else j--;
    }
    for(i=k;i>=1;i--)
    {
        fout<<st[i]<<" ";
    }
    return 0;
}
