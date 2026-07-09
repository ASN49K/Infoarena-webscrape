#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;
long long a, b;

int cmmdc(long long a, long long b)
{
    if(b==0) return a;
    return cmmdc(b, a%b);
}

int main()
{
    fin>>t;
    for(int i=1; i<=t; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a, b)<<'\n';
    }
}
