#include <bits/stdc++.h>
std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");

int gcd(int a,int b,int d)
{
    if(a == b)
        return a * pow(2,d);
    if(a%2 == 0 && b%2 == 0)
        gcd(a/2,b/2,d+1);
    else
        if(a%2 == 1 && b%2 == 0)
            gcd(a,b/2,d);
        else
            if(a%2 == 0 && b%2 == 1)
                gcd(a/2,b,d);
            else
                if(a%2 == 1 && b%2 == 1)
                        gcd(abs(b-a)/2,std::min(a,b),d);
}

int main()
{
    int n,a,b;
    in >> n;
    while(n --> 0)
    {
        in >> a >> b;
        out << gcd(a,b,0) << "\n";
    }
    return 0;
}
