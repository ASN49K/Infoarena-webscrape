#include <fstream>
#include <iostream>
using namespace std;
int t, a, b;

int cmmdc(int x, int y)
{
    int rest;
    while (y)
    {
        rest = x % y;
        x = y;
        y = rest;
    }
    return x;
}

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << cmmdc(a, b) << '\n';
    }
    return 0;
}

