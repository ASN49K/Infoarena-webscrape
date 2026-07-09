#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

void rezolva(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    out << a << '\n';
}

int main()
{
    int n, a, b;
    in >> n;

    for (int i = 0; i < n; i++)
    {
        in >> a >> b;
        rezolva(a, b);
    }

    return 0;
}