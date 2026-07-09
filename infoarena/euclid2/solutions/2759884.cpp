#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    int maxim;
    if (a == b)
        return a;
    for (int i = 1; i <= max(a, b) / 2; i++)
    {
        if (a % i == 0 && b % i == 0)
            maxim = i;
    }
    return maxim;
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