/*
    "TLE is like the wind, always by my side"
    - Yasuo - 2022 -
*/
#include <bits/stdc++.h>
#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "

using namespace std;

int gcd(int a,int b)
{
    if (b!=0)
        return gcd(b,a%b);
    else
        return a;
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n,i,a,b;
    fin >> n;
    for (i=1;i<=n;i++)
    {
        fin >> a >> b;
        fout << gcd(a,b) << "\n";
    }
}
