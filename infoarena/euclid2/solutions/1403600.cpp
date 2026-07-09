#include<bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

#define cout g
 int n,a,b;

int main()
{
    f>>n;
    for(;n;--n)
    {
        f>>a>>b;
        cout<<__gcd(a,b)<<'\n';
    }
    return 0;
}
