#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int GCD(int x, int y)
{
    if (!y)
        return x;
    return GCD(y, x%y);
}

int main()
{
    int n, a, b;
    fin >>n;
    for (; n > 0; --n)
    {
        fin >>a >>b;
        fout <<GCD(a, b) <<'\n';
    }
    return 0;
}
