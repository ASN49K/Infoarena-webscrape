#include <iostream>
#include <fstream>

using namespace std;

int euclid(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int t, a, b, ca;
    f>>t;
    for (int i = 0; i < t; i++)
    {
        f>>a>>b;
        ca = a;
        a = max(a, b);
        b = min(ca, b);
        g<<euclid(a, b)<<endl;
    }
    return 0;
}
