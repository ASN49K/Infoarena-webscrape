#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, x, y;
int gcd(int a, int b){
    int r;
    do{
        r = a % b;
        a = b;
        b = r;
    }
    while(r);
    return a;
}
int main()
{
    fin >> t;
    while(t--){
        fin >> x >> y;
        fout << gcd(x, y) << '\n';
    }
}
