#include<bits/stdc++.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,r,T;
int main()
{
f>>T;
while(T--)
{
f>>a>>b;
g<<std::__gcd(a,b)<<"\n";
}

}