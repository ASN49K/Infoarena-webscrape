#include <fstream>

using namespace std;
int a[1025],b[1025],v[1025][1025],s[1025],ct,n,m;;
void citire()
{   int i;
    ifstream f("cmlsc.in");
    f>>m>>n;
    for(i=1;i<=m;i++)
       f>>a[i];
    for(i=1;i<=n;i++)
       f>>b[i];
    f.close();
}
void solve()
{   int i,j;
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
        if(a[i]==b[j])
          v[i][j]=1+v[i-1][j-1];
         else
          {
              if(v[i-1][j]>v[i][j-1])
                 v[i][j]=v[i-1][j];
              else
                 v[i][j]=v[i][j-1];
          }
     i=m; j=n;
     while(i && j)
       if(a[i]==b[j])
         {
            ct++;
            s[ct]=a[i];
            i--; j--;
         }
        else
        {
            if(v[i-1][j]<v[i][j-1])
               j--;
            else
             i--;
        }
}
void afisare()
{   int i;
    ofstream g("cmlsc.out");
    g<<ct<<'\n';
    for(i=ct;i>=1;i--)
      g<<s[i]<<" ";
    g.close();
}
int main()
{
    citire();
    solve();
    afisare();
    return 0;
}
