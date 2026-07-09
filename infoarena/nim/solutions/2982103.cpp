#include <bits/stdc++.h>
using namespace std;
string np = "nim";
ifstream f(np + ".in");
ofstream g(np + ".out");

// #define f cin
// #define g cout

void solve(int n)
{
    int rez = 0;
    for (int x; n--;)
        f >> x, rez ^= x;
    if (rez)
        g << "DA\n";
    else
        g << "NU\n";
}
int main()
{
    int t;
    f >> t;
    for (int n; t--;)
        f >> n, solve(n);

    return 0;
}
