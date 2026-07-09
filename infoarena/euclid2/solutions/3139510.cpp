#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int euclid(int a,int b){
    while(b){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    fin>>n;
    for(int i=1;i<=n;++i){
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
