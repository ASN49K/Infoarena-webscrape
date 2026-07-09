#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int Euclid(int a ,int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, a, b, i;
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> a >> b;
        g << Euclid(a, b) << "\n";
    }
    f.close();
    return 0;
}
