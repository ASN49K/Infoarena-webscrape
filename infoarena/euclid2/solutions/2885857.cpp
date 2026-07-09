#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int tst,a,b;
int main()
{
    in>>tst;
    while(tst--)
    {
        in>>a>>b;
        out<<__gcd(a,b)<<'\n';
    }
    return 0;
}
