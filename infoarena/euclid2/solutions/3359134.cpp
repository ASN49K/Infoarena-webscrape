#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;
inline int gcd(int a ,int b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin >> t;
    while(t--){
        int a , b; fin >> a >> b;
        fout << gcd(a , b) << '\n';
    }
    return 0;
}
