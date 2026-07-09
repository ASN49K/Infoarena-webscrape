#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[257],b[257],c[513];
int main()
{
    int n,m,i,j,nu=0,nr=0,k=1;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=nu+1;j<=m;j++)
            if(a[i]==b[j])
            {
                nr++;
                c[k++]=a[i];
                nu=i;
            }
    g<<nr<<"\n";
    for(i=1;i<k;i++)
        g<<c[i]<<" ";
    f.close();
    g.close();
    return 0;
}
