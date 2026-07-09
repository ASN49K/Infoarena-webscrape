#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int euclid(int a, int b)
{
    while (a > 0 && b > 0)
        if (a > b) a -= b;
        else b -= a;

    if (a != 0)
        return a;

    if (b != 0)
        return b;
    return 0;
}

int main()
{
    int t, a, b;

    fi>>t;

    for (int i = 0; i < t; i++) {
        fi>>a>>b;

        fo<<euclid(a, b)<<endl;
    }

    fo.close();
    return 0;
}
