#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b;
int euclid(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    fin.tie(0);
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";
    }
    return 0;
}
