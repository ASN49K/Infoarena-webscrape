#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
struct cale{int x,y;};
#define Nmax 1025
cale d[Nmax];
int a[Nmax],b[Nmax],nr=-1000,v[Nmax],m,n;
int main()
{
    int i,j,k=0;
    f>>m>>n;
    for(i=1;i<=m;i++)
       f>>a[i];
    for(i=1;i<=n;i++)
       f>>b[i];
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
           if(a[i]==b[j])
              {v[++k]=j;
              j=n+1;}
    for(i=k;i>=1;i--)
       {j=i+1;
       while(v[i]>v[j]&&j<=k)
            j++;
       if(j<=k)
          {d[i].y=j;
          d[i].x=d[j].x+1;
          if(d[i].x>nr)
             nr=d[i].x;}
       else
          {d[i].y=0;
          d[i].x=1;
          if(d[i].x>nr)
             nr=d[i].x;}}
    g<<nr<<'\n';
    for(i=1;i<=k;i++)
         if(d[i].x==nr)
            {g<<b[v[i]]<<' ';
            while(d[i].y!=0)
                 {g<<b[v[d[i].y]]<<' ';
                 i=d[i].y;}
            i=k;}
    f.close();g.close();
}
