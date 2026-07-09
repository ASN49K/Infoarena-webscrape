#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int erat(int a,int b)
{
    if(!b)return a;
    return erat(b,a%b);
}
int main()
{
    long long a,b,n;
    fin>>n;
    for(;n;--n){
        fin>>a>>b;
        fout<<erat(a,b)<<'\n';
    }
    return 0;
}
