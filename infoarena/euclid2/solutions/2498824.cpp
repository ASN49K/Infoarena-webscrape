#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int t;
    f>>t;
    while(t--)
    {
        int a,b;
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }


    return 0;
}
