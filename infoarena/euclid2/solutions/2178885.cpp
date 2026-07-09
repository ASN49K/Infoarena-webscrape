#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,t;
int cmmdc(int a, int b)
{
    if(!b) return a;
    else return cmmdc(b,a%b);
}

int main()
{
    fin>>t;
    for(;t;t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
