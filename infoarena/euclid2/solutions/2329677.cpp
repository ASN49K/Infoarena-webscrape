#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,t;

int euclid(int a,int b)
{
    if(b==0)
        return a;
    else euclid(b,a%b);
}

int main()
{
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
