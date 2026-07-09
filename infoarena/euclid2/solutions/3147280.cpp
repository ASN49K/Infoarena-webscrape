#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int t, a, b, r;
    while (t--)
    {
        fin>>a>>b;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fout << a << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
