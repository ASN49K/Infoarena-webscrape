#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int x, int y){
    int r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int main(){
    int n,a,b;

    f>>n;
    for(int i=1; i<=n; ++i){
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
