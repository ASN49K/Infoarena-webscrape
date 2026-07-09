#include<bits/stdc++.h>
std::ifstream F("euclid2.in");
std::ofstream G("euclid2.out");
int a,b;
int main()
{
    for(F>>a;F>>a>>b;G<<std::__gcd(a,b)<<endl);
    return 0;
}
