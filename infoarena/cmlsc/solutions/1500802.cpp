#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1024],b[1024];
void rez()
{
    int i,j,nr=0,sol[1024];sol[0]=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j] && sol[nr]<a[i])
        {
            nr++;
            sol[nr]=a[i];
        }
    }
    g<<nr<<'\n';
    for(i=1;i<=nr;i++)
        g<<sol[i]<<" ";
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
    rez();
    return 0;
}
