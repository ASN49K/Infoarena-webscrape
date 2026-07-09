#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int gcd(int a, int b)
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
    int t, a, b;
    fin >> t;
    while(t--)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
    return 0;
}