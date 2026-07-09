#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int tst,a,b;
    in>>tst;
    while(tst--)
    {
        in>>a>>b;
        out<<__gcd(a,b)<<'\n';
    }
    return 0;
}
