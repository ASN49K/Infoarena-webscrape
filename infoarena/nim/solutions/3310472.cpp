#include <bits/stdc++.h>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int i,j,n,t,s,x;

int main()
{
  fin>>t;
  for(i=1;i<=t;i++)
  {
    fin>>n;
    for(j=1;j<=n;j++)
      {
        fin>>x;
        s^=x;
      }
    if(s)
      fout<<"DA"<<'\n';
    else
      fout<<"NU"<<'\n';
    s=0;
  }
  return 0;
}
