#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euc(int x,int y)
{
    int r;
    while (y)
    {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}
int main()
{
    int p,a,b;
    in >> p;
    while (p--)
    {
        in >> a >> b;
        out << euc(a,b) << "\n";
    }
    return 0;
}
