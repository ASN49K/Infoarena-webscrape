#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,a[1030],b[1030],sol[1030],nr,mat[1025][1025];
void f(int i,int j,int nr)
{
    if(nr>0)
    {
        if(a[i]==b[j])
        {
            f(i-1,j-1,nr-1);
            cout<<a[i]<<" ";
        }
        else if(mat[i-1][j]>mat[i][j-1])
            f(i-1,j,nr);
        else
        f(i,j-1,nr);

    }
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int j=1; j<=m; j++)
        cin>>b[j];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                mat[i][j]=mat[i-1][j-1]+1;
            else
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    cout<<mat[n][m]<<'\n';

    f(n,m,mat[n][m]);
    return 0;
}
