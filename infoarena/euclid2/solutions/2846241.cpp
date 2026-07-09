#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int T,a,b;
    f>>T;
    for(int i=1;i<=T;i++){
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
    }
    return 0;
}
