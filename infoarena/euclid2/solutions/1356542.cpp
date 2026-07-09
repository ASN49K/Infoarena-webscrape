#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int n,a,b,c;
    f>>n;
    while(n)
    {
        f>>a>>b;
        c=__gcd(a,b);
        g<<c<<endl;
        n--;
    }

    return 0;
}
