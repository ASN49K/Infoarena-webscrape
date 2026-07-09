#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

int cmmdc(int a, int b)
{
    while (b != 0) {
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

void do_test()
{
    int a, b;
    f >> a >> b;
    g << cmmdc(a, b) << '\n';
}

int main()
{
    int t;
    f >> t;
    for (int i = 1; i <= t; i++) {
        do_test();
    }

    f.close();
    g.close();
    return 0;
}
