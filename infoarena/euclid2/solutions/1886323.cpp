#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,a,b;

int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}

int main()
{
    fin>>T;
    while(T--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
