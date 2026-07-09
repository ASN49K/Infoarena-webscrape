#include<bits/stdc++.h>
using namespace std;
int v1[1025], v2[1025],r[1035];
int d[1026][1026];
int
main ()
{
  ifstream f ("cmlsc.in");
  ofstream g ("cmlsc.out");

  int n, m;

  f>> n >> m;

  for (int i = 1; i <= n; i++)
    f >> v1[i];
  for (int i = 1; i <= m; i++)
   f >> v2[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      {
	if (v1[i] == v2[j])
	  d[i][j] = d[i - 1][j - 1] + 1;
	else
	  d[i][j] = max (d[i - 1][j], d[i][j - 1]);
      }
  g<< d[n][m]<<"\n";
int i=n, j=m,contor=0;
while(i>=1 && j>=1)
{
    if(v1[i]==v2[j])
    {
        i--;
        j--;
        r[contor]=v1[i+1];
        contor++;
    }
    else if(d[i-1][j]>d[i][j-1]) i--;
    else j--;
}
for(int x=contor-1;x>=0;x--) g<<r[x]<<" ";
}

