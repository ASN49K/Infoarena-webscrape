#include <bits/stdc++.h>
#define UI unsigned int

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
UI t, a, b;

UI cmmdc(UI a, UI b)
{
    UI rest;

    while(b)
    {
        rest = a % b;
        a = b;
        b = rest;
    }

    return a;
}

int main()
{
    in >> t;

    while(t--)
    {
        in >> a >> b;
        out << cmmdc(a, b) << '\n';
    }

    return 0;
}
