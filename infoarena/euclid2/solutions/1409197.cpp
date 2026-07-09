#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#ifdef INFOARENA
ifstream f("euclid2.in");
#define cout g
#else
ifstream f("date.in");
#endif // INFOARENA

ofstream g("euclid2.out");

int a,b,n;

int main()
{
    f>>n;
    for(;n;--n)
    {
        f>>a>>b;
        cout<<__gcd(a,b)<<'\n';
    }
    return 0;
}
