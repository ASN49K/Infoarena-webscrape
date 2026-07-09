#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1000], b[1000],c[1000],i,j,maxi,n,m,p,r;
int main()
{
    fin>>n>>m;

    for(i=1;i<=n;i++)
        fin>>a[i];

    for(i=1;i<=m;i++)
        fin>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j] && maxi<=j)
        {
            p++;
            c[p]=a[i];
            r++;
            maxi=j;

        }
    }
    fout<<r<<'\n';

    for(i=1;i<=p;i++)
        fout<<c[i]<<" ";

    return 0;
}
