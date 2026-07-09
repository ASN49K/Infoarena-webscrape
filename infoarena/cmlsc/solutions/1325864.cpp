#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],n,m;
struct vector{int ant,nr;} v1[1025],v2[1025];
void cons(vector s1[],vector s2[],int var)
{
    for(int i=1;i<=m;i++)
        s2[i]=s1[i];
    for(int i=1;i<=m;i++)
        if(b[i]==var)
        {
            if(s2[i].nr==0) s2[i].nr=1,s2[i].ant=0;
            for(int j=1;j<i;j++)
                if(s2[i].nr<s1[j].nr+1) s2[i].nr=s1[j].nr+1,s2[i].ant=j;
        }
}
void determin(vector v[])
{
    int vmax=0,poz;
    for(int i=1;i<=m;i++)
        if(v[i].nr>vmax) vmax=v[i].nr,poz=i;
    fout<<vmax<<'\n';
    int k[1025],nrc=0;
    while(poz!=0)
        k[++nrc]=poz,poz=v[poz].ant;
    for(int i=vmax;i>=1;i--)
        fout<<b[k[i]]<<' ';
}
void rezolv()
{
    int poz;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
            cons(v1,v2,a[i]);
        else
            cons(v2,v1,a[i]);
    }
    if(n%2==1)
        determin(v2);
    else
        determin(v1);
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
