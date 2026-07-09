#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in ("nim.in");
    ofstream out ("nim.out");

    int n;
    int s;
    in >> n;

    for (; n; n--)
    {
        s = 0;
        int x, t;
        in >> x;
        for (int i = 0; i < x; i++)
            in >> t, s ^=  t;
        if (s)
            out << "DA\n";
        else
            out << "NU\n";
    }

    return 0;
}
