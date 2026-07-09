#include <bits/stdc++.h>
using namespace std;
ifstream in ("nim.in");
ofstream out ("nim.out");

int main()
{
    int t, n, p_crt;
    int val;

    in >> t;

    for(int i = 1; i <= t; i++)
    {
        in >> n;
        val = 0;
        for(int j = 1; j <= n; j++)
        {
            in >> p_crt;
            val ^= p_crt;
        }
        if(val)
            out << "DA";
        else
            out << "NU";
        out << '\n';
    }
    return 0;
}