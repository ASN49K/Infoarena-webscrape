#include <bits/stdc++.h>
#define Dim 100007
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,A,B;

int main()
{
    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>A>>B;
        g<<__gcd(A,B)<<'\n';
    }
    return 0;
}
