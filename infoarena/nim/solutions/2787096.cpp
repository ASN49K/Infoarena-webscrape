#include <bits/stdc++.h>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, r, x;

    fin >> t;
    while(t--)
    {
        fin >> n;
        r = 0;
        while(n--) fin >> x, r ^= x;
        if(r == 0) fout << "NU" << '\n';
        else fout << "DA" << '\n';
    }


    return 0;
}
