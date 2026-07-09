#include <bits/stdc++.h>
#define oo 1000000007
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,n;
int main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(0);
    fout.tie(0);
    fin >> n;
    while(n--)
    {
       fin >> a >> b;
       fout << __gcd(a,b) << "\n";
    }
    return 0;
}
