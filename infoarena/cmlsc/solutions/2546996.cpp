#include <bits/stdc++.h>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int const lim=1025;
int n,m,a[lim],b[lim],v[lim][lim];
vector < int > c;

int mx(int x, int y)
{
    if(x>y) return x;
    return y;
}

int main()
{
   in>>n>>m;
   for(int i=1;i<=n;i++)
    in>>a[i];
   for(int i=1;i<=m;i++)
    in>>b[i];

   for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i]==b[j])
   {
       v[i][j]=v[i-1][j-1]+1;
   }
   else
   {
       v[i][j]=mx(v[i-1][j],v[i][j-1]);
   }

   out<<v[n][m]<<'\n';

   while(n!=0 && m!=0)
   {
       if(v[n-1][m]==v[n][m])
       {
           n--;
       }
       else if(v[n][m-1]==v[n][m])
       {
           m--;
       }
       else
       {
           c.push_back(a[n]);
           n--;
           m--;
       }
   }

   for(int i=c.size()-1;i>=0;i--)
    out<<c[i]<<" ";
}
