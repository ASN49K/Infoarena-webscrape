#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    int r = a % b;
    while(r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int main()
{
    int T;
    in >> T;
    for(int i = 1; i <= T; i++)
    {
        int a, b;
        in >> a >> b;
        out << cmmdc(a, b) << "\n";
    }
    return 0;
}
