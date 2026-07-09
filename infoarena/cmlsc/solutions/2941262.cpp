#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[1025],b[1025],dp[1025][1025],s[1025];

int main()
{
    int i,j,n,m,nr=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    for(i=n,j=m;i>0;)
        if(a[i]==b[j])
        {
            s[++nr]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else
            i--;

    cout<<nr<<endl;
    for(i=nr;i>0;i--)
        cout<<s[i]<<" ";
    return 0;
}
