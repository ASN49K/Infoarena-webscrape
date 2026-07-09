#include<bits/stdc++.h>
using namespace std;
ifstream g("euclid2.in");
ofstream f("euclid2.out");
int t,a,b,c;
int main(){
    g>>t;
    for(;t--;) g>>a>>b, f<<__gcd(a,b)<<"\n";
}
