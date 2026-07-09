#include <iostream>
#include <fstream>

using namespace std;


ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int nrTeste;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    fi>>nrTeste;

    for(int test=1; test<=nrTeste; test++)
    {
        int a,b;
        fi>>a>>b;
        fo<<gcd(a,b)<<"\n";
    }
    return 0;
}
