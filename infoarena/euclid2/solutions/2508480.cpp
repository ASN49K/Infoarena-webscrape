#include<bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t,a,b;
int cmmdc(int a,int b)
{
    int r=0;
    r=a%b;
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
    fin>>t;
    for ( int i = 1; i <= t; i++ )
    {
        fin >> a >> b;
        fout << cmmdc(a,b)<<"\n";
    }
    return 0;
}
