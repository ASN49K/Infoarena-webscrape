#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int n;
    in >> n;

    for(int i = 1; i <= n; i++)
    {
        int a, b;
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }

    return 0;
}
