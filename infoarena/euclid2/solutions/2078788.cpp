#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a,int b)
{
    if(b==0)
        return a;
    else
        euclid(b,a%b);
}

int main()
{
    int a,b,n,i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";
    }
    return 0;
}
