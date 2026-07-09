#include <iostream>
#include <fstream>

using namespace std;

int euclid (int a, int b)
{
    int c;

    while (b!=0)
    {
        c = a%b;
        a = b;
        b = c;

    }

    return a;
}



int main()
{

    ifstream in ("euclid2.in");
    ofstream out ("euclid2.out");

    int q, i, a, b;

    in >> q;

    for (i = 1; i<= q; i++)
    {
        in >> a >> b;

        out << euclid(a, b) << endl;
    }

    return 0;
}
