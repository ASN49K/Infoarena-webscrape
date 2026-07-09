#include <fstream>
#include <cmath>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int a[1025], b[1025], c[1025][1025], d[1024];
int main()
{
    int m, n, k=0;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];

    for(int i=1;i<=m;i++)
        fin>>b[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;

            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
        }

    int i=n, j=m;
    while(i!=0 or j!=0)
    {
        if(a[i]==b[j])
        {
            d[++k]=a[i];
            i--;
            j--;
        }
        else if(c[i-1][j]<c[i][j-1])
            j--;
        else
            i--;
    }

    fout<<k<<'\n';
    for(int l=k;l>0;l--)
        fout<<d[l]<<' ';

    return 0;
}
