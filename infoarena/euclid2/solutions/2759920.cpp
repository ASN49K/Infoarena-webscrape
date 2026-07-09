#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    if (!b) return a;
    if (a > b)  cmmdc(a - b,b);
    cmmdc(b-a,a);
}

int main() {

    int T;
    in >> T;
    for (int i = 1; i <= T; i++)
    {
        long a, b;
        in >> a >> b;
        out << cmmdc(a, b) << endl;
    }
    return 0;
}