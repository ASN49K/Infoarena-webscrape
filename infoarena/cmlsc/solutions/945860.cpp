#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n1,n2,i,j,x,y,s,c[1025],a[1025],b[1025],v[1025][1025];
int main()
{
    f>>n1>>n2;
    for (i=1;i<=n1;i++)
     f>>a[i];
    for (i=1;i<=n2;i++)
     f>>b[i];
    for (i=1;i<=n1;i++)
     for (j=1;j<=n2;j++)
         if (a[i]==b[j])
          v[i][j]=v[i-1][j-1]+1;
         else v[i][j]=v[i-1][j]>v[i][j-1]?v[i-1][j]:v[i][j-1];
    g<<v[n1][n2]<<'\n';
    y=n1;x=n2;
    while (v[y][x])
    {
        if (a[y]==b[x]){s++;c[s]=a[y];y--;x--;}
        else
        if (v[y-1][x]<v[y][x-1])x--;
        else y--;
    }
    for (i=s;i>=1;i--)g<<c[i]<<" ";
   f.close();
   g.close();
}
