#include<fstream>
#define nmax 800
#define lmax 640000
using namespace std;
ifstream f("cmlsc.in",fstream::in);
ofstream g("cmlsc.out",fstream::out);
unsigned int a[nmax],b[nmax],c[nmax][nmax],sol[lmax],nrsol,maximul;
short int n,m;
unsigned int maxim(unsigned int a,unsigned int b)
{
    if(a>b)
        return a;
    else
        return b;
}
void citire()
{
    short int i;
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
}
void phd()
{
    short int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=maxim(c[i-1][j],c[i][j-1]);
}
void solve()
{
    short int i,j;
    i=n;j=m;
    for(i=n,j=m;i;)
     if(a[i]==b[j])
     sol[++nrsol]=a[i],--i,--j;
     else
     if(c[i][j-1]>c[i-1][j])
     --j;
     else
     --i;
}
void afis_m()
{unsigned short int i,j;
 for(i=1;i<=n;i++)
 {
     for(j=1;j<=m;j++)
     g<<c[i][j]<<" ";
     g<<"\n";
 }
}
void show()
{
    unsigned int i;
    g<<nrsol<<"\n";
    for(i=nrsol;i;i--)
    g<<sol[i]<<" ";
}
int main()
{
    citire();
    phd();
  //  afis_m();
    solve();
    show();
    f.close();
    g.close();
    return 0;
}
