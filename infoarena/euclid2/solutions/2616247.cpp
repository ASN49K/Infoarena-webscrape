#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned long long gcd(unsigned long long a, unsigned long long b){
    if (!b) return a;
    return gcd(b, a%b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    fin.tie(0);

    int t;
    fin >> t;
    while (t--){
        unsigned long long a, b;
        fin >> a >> b;
        fout << gcd(a,b) << "\n";
    }
    return 0;
}
