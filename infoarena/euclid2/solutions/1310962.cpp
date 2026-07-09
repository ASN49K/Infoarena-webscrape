#include <bits/stdc++.h>
using namespace std;
int a,b,n;
int main()
{
 ifstream cin("euclid2.in");
 ofstream cout("euclid2.out");
 cin>>n;
  while(n--)
   {
    cin>>a>>b;
    cout<<__gcd(a,b)<<"\n";
   }
 return 0;
}
