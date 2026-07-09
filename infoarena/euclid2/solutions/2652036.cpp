#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long long n,a,b;
long long gcd(long long a,long  long b)
{
   while(b!=0)
   {
       long long r=a%b;
       a=b;
       b=r;
   }
   return a;
}
int main()
{
    in>>n;
    while(n--)
    {
        in>>a>>b;
        out<<gcd(a,b)<<'\n';
    }
    return 0;
}
