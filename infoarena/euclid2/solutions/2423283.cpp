#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n, a, b;
int cmmdc(int a, int b)
{
    if(b == 0) return a;
    return cmmdc(b, a % b);
}
int main()
{
    f >> n;
    while(n--)
    {
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
}
