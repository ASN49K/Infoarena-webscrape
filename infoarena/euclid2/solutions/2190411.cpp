#include <bits/stdc++.h>
using namespace std;
int a,b,t;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    fin>>t;;
    // cout<<cmmdc(a,b);
    while(t--)
    {
        fin>>a>>b;
        fout<<__gcd(a,b)<<"\n";
    }
    return 0;
}
