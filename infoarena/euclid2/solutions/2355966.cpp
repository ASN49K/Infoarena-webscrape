#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b;

int gcd(int a,int b)
{
    int r;
    while(b>0)r=a%b,a=b,b=r;
    return a;
}
int main()
{
    f>>T;
    while(T--)
    {
        f>>a>>b;
        g<<gcd(a,b)<<"\n";
    }
    return 0;
}
