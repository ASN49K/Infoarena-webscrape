#include <iostream>

using namespace std;

void euclid(int a, int b, int &d)
{
    if (b == 0) {
        d = a;
    } else
        euclid(b, a % b, d);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,d;
    f>>t;
    for(t;t;--t)
    {
        f>>a>>b;
        euclid(a,b,d)
        g<<d<<'\n';
    }

    return 0;
}
