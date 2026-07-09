#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int t; cin >> t;
    int nr, element, xorsum;

    for(int i = 0; i < t; i++)
    {
        xorsum = 0;
        cin >> nr;

        for(int i = 0; i < nr; i++)
        {
            cin >> element;

            xorsum ^= element;
        }

        (xorsum) ? cout << "DA\n" : cout << "NU\n";
    }
}
