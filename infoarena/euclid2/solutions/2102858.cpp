#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;

int cmmdc(int a, int b)
{
    int c;
    while(a%b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return b;
}

int main()
{
    fin>>n;
    int a, b;
    for(int i=1; i<=n; ++i)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
