#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;

int cmmdc(int a, int b)
{
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
    f >> n;

    for(int i = 1; i <= n; i++)
    {
        int a, b;
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }


    return 0;
}
