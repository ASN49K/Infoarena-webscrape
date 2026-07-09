#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int gcd( int a, int b)
{
    if(!b)return a;
    else return gcd(b,a%b);
}
int main()
{
    int n;
    fin>>n;
    while( n)
    {
        int x, y;
        fin >> x >>y;
        fout << gcd(x,y) << "\n";
        --n;
    }
    return 0;
}
