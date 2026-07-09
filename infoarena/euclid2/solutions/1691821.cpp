#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

int C;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int T, a,b;
    f>>T;
    for(;T;--T){
    f>> a >> b;
    g<< gcd(a, b) << '\n';

    }


    g.close();
    f.close();
    return 0;
}

