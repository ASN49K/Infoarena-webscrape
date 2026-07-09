#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f >> n;
for(int i = 0, x, y; i < n; ++i){
f >> x >> y;
g << __gcd(x, y) << '\n';
}
return 0;
}
