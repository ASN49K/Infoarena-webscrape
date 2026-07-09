#include <iostream>
#include <fstream>

int cmmdc(int a, int b)
{
    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

int main()
{
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");

    int t;
    in >> t;

    while (t--)
    {
        int a, b;
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }

    return 0;
}
