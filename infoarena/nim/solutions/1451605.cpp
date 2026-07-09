#include<bits/stdc++.h>
using namespace std;

int t,n,sum,x;

int main()
{
  ifstream cin("nim.in");
  ofstream cout("nim.out");

  for(cin>>t;t;--t)
  {
    for(cin>>n,sum=0;n;--n) cin>>x,sum^=x;
    cout<<(sum ? "DA":"NU")<<'\n';
  }

 return 0;
}
