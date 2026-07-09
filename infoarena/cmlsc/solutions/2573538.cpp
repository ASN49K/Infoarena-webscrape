#include <bits/stdc++.h>
#define nmax 1025
#define pb push_back
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[nmax],b[nmax],d[nmax][nmax],k,sir[nmax];

/*vector <pair<int,int> > v[nmax];
priority_queue <pair<int,int> > q;*/


int main()
{
  f>>n>>m;
  for(i=1;i<=n;i++)
    f>>a[i];
  for(i=1;i<=m;i++)
    f>>b[i];

  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    if(a[i]==b[j])
    d[i][j]=1+d[i-1][j-1];
  else
    d[i][j]=max(d[i-1][j],d[i][j-1]);

  j=m;
  for(i=n;i>=1;)
  {
      if(a[i]==b[j])
      {
          k++;
          sir[k]=a[i];
          i--;j--;
      }
      else
        if(d[i-1][j]<d[i][j-1])
        j--;
      else
        i--;

  }

  g<<k<<"\n";
  for(i=k;i>=1;i--)
    g<<sir[i]<<" ";

  return 0;

}
