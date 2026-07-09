#include<fstream>
#define lmax 1025
using namespace std;
ifstream f("cmlsc.in",fstream::in);
ofstream g("cmlsc.out",fstream::out);
unsigned short int a[lmax],b[lmax],c[lmax][lmax],n,m,sol[lmax],nrsol;
int maxim(short int a,short int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void citire()
{ f>>n>>m;
  for(unsigned short int i=1;i<=n;i++)
  f>>a[i];
  for(unsigned short int i=1;i<=m;i++)
  f>>b[i];
}
void phd()
{ for(unsigned short int i=1;i<=n;i++)
   for(unsigned short int j=1;j<=m;j++)
     if(a[i]==b[j])
      {
          c[i][j]=c[i-1][j-1]+1;
          sol[++nrsol]=a[i];
      }
    else
    c[i][j]=maxim(c[i-1][j],c[i][j-1]);
}
void tipar()
{   g<<nrsol<<"\n";
    for(unsigned short int i=1;i<=nrsol;i++)
    g<<sol[i]<<" ";
}
int main()
{
    citire();
    phd();
    tipar();
    f.close();
    g.close();
    return 0;
}
