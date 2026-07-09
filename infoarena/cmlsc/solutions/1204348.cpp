#include <fstream>
#include <iostream>
#define MAX(a,b) ((a>b) ? a : b )


using namespace std;

int s[1030],v[1030],ras[1030],x[1030][1030];
main()
{
  int k,l;
  ifstream fi("cmlsc.in");
  ofstream fo("cmlsc.out");
  fi>>k>>l;
  int i,j;
  for (i=1;i<=k;i++)
     fi>>s[i];
  for (i=1;i<=l;i++)
    fi>>v[i];
  for (i=1;i<=k;i++)
    for (j=1;j<=l;j++)
      if (s[i] == v[j])
         x[i][j]=1+x[i-1][j-1];
        else
         x[i][j]=MAX(x[i-1][j],x[i][j-1]);
  int p=0;
  i=k;j=l;
  while (i>0 && j>0)
  {
      if (s[i] == v[j])
      {
          ras[++p]=s[i];
          i--;
          j--;
      }
      else
      if (x[i-1][j]>x[i][j-1])
      i--;
      else
      j--;
  }
  fo<<p<<"\n";
  for (i=p;i>=1;i--)
     fo<<ras[i]<<" ";
  fo.close();
  fi.close();
}
