#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],n,m;
struct vector{int ant,nr;} v[1025];
void rezolv()
{
    int poz;
    for(int i=1;i<=n;i++)
    {
        int poz=1;
        for(int j=1;j<=m;j++)
            if(b[j]==a[i])
            {
                v[j].nr=1; v[j].ant=0;
                for(int i=poz;i<j;i++)
                    if(v[j].nr<v[i].nr+1) v[j].nr=v[i].nr+1,v[j].ant=i;
                poz=j+1;
            }
    }
    int vmax=0;
    for(int i=1;i<=m;i++)
        if(v[i].nr>vmax) vmax=v[i].nr,poz=i;
    fout<<vmax<<'\n';
    int k[1025],nrc=0;
    while(poz!=0)
        k[++nrc]=poz,poz=v[poz].ant;
    for(int i=vmax;i>=1;i--)
        fout<<b[k[i]]<<' ';
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    rezolv();
    return 0;
}
