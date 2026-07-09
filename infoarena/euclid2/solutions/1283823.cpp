#include <bits/stdc++.h>
using namespace std;

int a,b,n;

int gcd ( int a, int b)
 {
  if (a==0) return b;
  return gcd(b%a,a);
 }

int main()
{
 ifstream cin("euclid2.in");
 ofstream cout("euclid2.out");
 cin>>n;
  while(n--)
   {
   	cin>>a>>b;
   	cout<<gcd(a,b)<<"\n";
   }
 return 0;
}
