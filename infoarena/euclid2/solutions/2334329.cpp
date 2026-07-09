#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(long long a, long long b){
    int r=0;
    while(b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int n;
    long long x,y;
    in >> n;
    for(int i=0; i<n; ++i){
        in >> x >> y;
        out << euclid(x,y) << '\n';
    }
    return 0;
}
