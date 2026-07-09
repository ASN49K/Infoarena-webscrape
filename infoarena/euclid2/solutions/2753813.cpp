#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
long long n,a,b,t;
long long gcd(long long a,long long b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    in>>t;
    while(t--)
    {
        in>>a>>b;
        out<<gcd(a,b)<<'\n';
    }
    return 0;
}
