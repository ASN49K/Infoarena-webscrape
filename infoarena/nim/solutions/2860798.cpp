#include <bits/stdc++.h>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int t,n,X;

int main()
{
    in >> t;
    for (int i = 1; i <= t; i++)
    {
        in >> n;
        for (int j = 1; j <= n; j++)
        {
            int x;
            in >> x;
            X = X ^ x;
        }
        if (X == 0)
            out << "NU\n";
        else
            out << "DA\n";
    }
    return 0;
}
