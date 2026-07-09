#include <bits/stdc++.h>
using namespace std;int main(){ifstream f("euclid2.in");ofstream g("euclid2.out");int T;f>>T;while(T--){int a,b;f>>a>>b;g<<__gcd(a,b)<<"\n";}}