#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    if (a < b) {
        int aux = a;
        a = b;
        b = aux;
    }
    int last = a - b;
    while (last && b)
    {
        if (last > b)
            last -= b;
        else
            b -= last;
    }
    return max(b,last);
}

int main() {

    int T;
    in >> T;
    for (int i = 1; i <= T; i++)
    {
        int a, b;
        in >> a >> b;
        int x = cmmdc(a, b);
        out << x << endl;
    }
    return 0;
}