#include <iostream>
#include <fstream>

using namespace std;

int foo(int a, int b)
{
    if(b == 0) return a;

    foo(b, a % b);
}

int main()
{
    ifstream i("euclid2.in");
    ofstream o("euclid2.out");

    int x;

    i >> x;

    for(int a = 0; a < x; a++)
    {
        int k, j;

        i >> k >> j;

        o << foo(k, j) << '\n';
    }

    return 0;
}
