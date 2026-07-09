#include <iostream>
#include <fstream>

using namespace std;

ifstream fi("euclid2.in");
ofstream fo("euclid2.out");

int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b, a % b);
}

int main()
{
    int t, a, b;

    fi>>t;

    for (t; t; t--) {
        fi>>a>>b;

        fo<<euclid(a, b)<<"\n";
    }

    fo.close();
    return 0;
}
