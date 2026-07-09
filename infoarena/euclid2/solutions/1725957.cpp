#include<bits/stdc++.h>
#include<fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
int a,b,r,T;f>>T;
while(T--)
f>>a>>b,g<<std::__gcd(a,b)<<"\n";
}