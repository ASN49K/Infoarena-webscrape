#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");
int main()
{

    int t,x,y;
    in >> t;
    for(int i = 0 ; i < t ; i++)
    {
        in>> x >>  y;
        out<<std::__gcd(x,y)<<'\n';
    }
    return 0;
}
