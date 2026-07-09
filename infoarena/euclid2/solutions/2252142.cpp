#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int maco(int a,int b){
    int r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    long long n,i,x,y;
    fin>>n;
    for(i=0;i<n;++i){
        fin>>x>>y;
        fout<<maco(x,y)<<'\n';
    }
    return 0;
}
