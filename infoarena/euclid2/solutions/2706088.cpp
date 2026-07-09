#include <bits/stdc++.h>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main(){
    int t,a,b;
    in>>t;
    for(;t;t--)
    {
        in>>a>>b;
        out<<__gcd(a,b)<<"\n";
    }
}