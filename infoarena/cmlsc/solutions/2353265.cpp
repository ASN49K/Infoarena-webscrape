#include <fstream>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,i,j,v[1030],u[1030],a[1030][1030],sol[1030],lsol;

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v[i];
    for(i=1;i<=m;i++)
        cin>>u[i];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==u[j])
                a[i][j]=a[i-1][j-1]+1;
            else
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    }
    cout<<a[n][m]<<'\n';
    i=n;
    j=m;
    lsol=a[n][m];
    while(i>=1 && j>=1)
    {
        if(v[i]==u[j])
        {
            sol[lsol--]=v[i];
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]>a[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=1;i<=a[n][m];i++)
        cout<<sol[i]<<" ";
    return 0;
}
