#include <bits/stdc++.h>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main()
{
    int a, b, t, r;
    fin >> t;
    while(t != 0)
    {
        fin >> a >> b;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        t--;
        fout << a << '\n';
    }
    return 0;
}
