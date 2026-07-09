#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

void usain_bolt()
{
    ios::sync_with_stdio(false);
    fin.tie(0);
}

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main()
{
    usain_bolt();

    int tt;

    fin >> tt;
    for(; tt; --tt) {
        int x, y;

        fin >> x >> y;
        fout << gcd(x, y) << "\n";
    }
    return 0;
}
