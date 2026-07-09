#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int xx,y,max1,i,j,ok,x[5],n,a,b;
vector <int> v[101];

int eucl(int a,int b)
{
    while(b)
    {
       int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
  f>>n;
  for(i=1;i<=n;i++)

  {
       f>>a>>b;
       g<<eucl(a,b)<<'\n';
  }
    return 0;
}
