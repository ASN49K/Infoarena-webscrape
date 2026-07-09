#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int a,b,t,i;
int main()
{
    in>>t;
    for(i=1; i<=t; ++i)
        in>>a>>b,out<<__gcd(a,b)<<"\n";
}
