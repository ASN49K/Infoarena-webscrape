#include <iostream>
#include <fstream>

std::ifstream fi("euclid2.in");
std::ofstream fo("euclid2.out");

int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n, a, b;
    fi>>n;
    for(; n;--n)
    {
        fi>>a>>b;
        fo<<euclid(a,b)<<'\n';
    }

}
