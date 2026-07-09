#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[1025][1025];
int m,n;
short int a[1025];
short int b[1025];
int subsirSf[1025];

void backCit()
{
    int i,j,k=1;
    i=n;///linie
    j=m;///coloana
  while(v[i][j]!=0)
  {
      if(b[i]==a[j])
      {
          subsirSf[k]=b[i];
          i--;
          j--;
          k++;
      }
      else
      {
          if(v[i][j-1]>v[i-1][j])
          j--;
          else
          i--;
      }
  }

  g<<'\n';
  for(i=v[n][m];i>=1;i--)
  g<<subsirSf[i]<<' ';

}
int main()
{
    f>>m>>n;
    int i,k;
    for(i=1;i<=m;i++)
    f>>a[i];

    for(i=1;i<=n;i++)
    f>>b[i];

    for(i=1;i<=n;i++)
    {
        for(k=1;k<=m;k++)
        {
            if(b[i]==a[k])
            v[i][k]=v[i-1][k-1]+1;
            else
            {
                int d= max(v[i-1][k],v[i][k-1]);
                d= max(d,v[i-1][k-1]);

                v[i][k]=d;
            }
        }
    }

   g<<v[n][m];
    backCit();


     f.close();
     g.close();
    return 0;
}
