#include <bits/stdc++.h>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");
int n;

int main()
{
    int i,x, k;
    fin>>n;
    while (n--)
    {
        fin>>x>>k;
        fout<<__gcd(x,k)<<'\n';
    }
    return 0;
}



