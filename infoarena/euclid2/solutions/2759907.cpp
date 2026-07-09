#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    int last = a;
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
        out << cmmdc(a, b) << endl;
    }
    return 0;
}