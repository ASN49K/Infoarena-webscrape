# include <fstream>
# include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1050],b[1050],d[1050][1050],v[1050];
int i,j,n,m,nr;
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        f>>a[i];
    for (j=1; j<=m; ++j)
        f>>b[j];
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j)
        {
            if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
                else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    i=n; j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            v[++nr]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]>=d[i][j-1])
                i--;
             else
                j--;
    }

    g<<nr<<"\n";
    for(i=nr;i>=1;i--)
        g<<v[i]<<" ";
    return 0;



    return 0;
}
