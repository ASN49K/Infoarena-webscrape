#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int a, b, r, t;
int main()
{
    fin >> t;
    while(t--)
    {
        fin >> a >> b;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << "\n";
    }
    return 0;
}
