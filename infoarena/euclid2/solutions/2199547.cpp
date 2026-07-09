#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int q;
int a , b;
int gcd(int x, int y)
{
    if (!y) return x;
    return gcd(y, x % y);
}
ifstream in("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    in >> q;
    while(q--){
    in >> a >> b;
    fout << gcd(a,b) << endl;
    }
    return 0;
}
