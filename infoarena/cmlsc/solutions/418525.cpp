#include <iostream>
#include <fstream>
using namespace std;
int c[1026][1026];
short int a[1026],b[1026];
ofstream g("cmlsc.out");
inline int maxim(int a, int b)
{
       if(a>=b) return a;
       return b;
}
void afiseaza(int i, int j)
{
     if(i>0&&j>0)
     {
     if(a[i]==b[j])
     {
                   afiseaza(i-1,j-1);    
                   g<<a[i]<<" ";
     }
     else
      if(c[i-1][j]<c[i][j-1])
       afiseaza(i,j-1);
      else
       afiseaza(i-1,j);
     }
}
int main()
{
    int m,n,i,j;
    ifstream f("cmlsc.in");
    f>>m>>n;
    for(i=1;i<=m;i++)
     f>>a[i];
    for(i=1;i<=n;i++)
     f>>b[i];
    for(i=1;i<=m;i++)
     for(j=1;j<=n;j++)
      if(a[i]==b[j])
       c[i][j]=c[i-1][j-1]+1;
      else
       c[i][j]=maxim(c[i-1][j],c[i][j-1]);
    g<<c[m][n]<<"\n";
    afiseaza(m,n);
    g<<"\n";
    f.close();
    g.close();
    return 0;
}
