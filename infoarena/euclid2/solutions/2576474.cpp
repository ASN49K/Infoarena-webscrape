#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int x, int y){
    int r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

int n,x,y;

int main(){

    f>>n;

    for(int i=1; i<=n; ++i){
        f>>x>>y;
        g<<euclid(x, y)<<'\n';;
    }

    return 0;
}
