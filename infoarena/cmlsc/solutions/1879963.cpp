#include <fstream>
#include <string.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1024],b[1024],n,m;
int lcs[100][100],max;

void LCS()
{
    for(int k=1;k<=n;k++)
       for(int h=1;h<=m;h++)
          if(a[k]==b[h]) lcs[k][h]=1+lcs[k-1][h-1];
          else if(lcs[k-1][h]>lcs[k][h-1]) lcs[k][h]=lcs[k-1][h];
               else lcs[k][h]=lcs[k][h-1];
}

void afiseaza_solutie(int k,int h)
{
     if(lcs[k][h])
        if(a[k]==b[h])
          {afiseaza_solutie(k-1,h-1);
           g<<a[k]<<' ';
          }
        else
          {if(lcs[k][h]==lcs[k-1][h])
              afiseaza_solutie(k-1,h);
           else if(lcs[k][h]==lcs[k][h-1])
                    afiseaza_solutie(k,h-1);
          }
}

int main()
{
      f>>n>>m;int i;
      for(i=1;i<=n;i++) f>>a[i];
      for(i=1;i<=m;i++) f>>b[i];
      LCS();
      g<<lcs[n][m]<<'\n';
      afiseaza_solutie(n,m);
      return 0;
}
