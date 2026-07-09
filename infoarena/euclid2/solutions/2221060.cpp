#import<bits/stdc++.h>
std::ifstream f("euclid2.in");std::ofstream g("euclid2.out");int main(){int N,a,b;for(f>>N;--N;f>>a,f>>b,g<<std::__gcd(a,b)<<'\n');}
