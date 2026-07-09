#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void Euclid(int a, int b)
{
    int r = 0;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    fout << a << "\n";
}

int main()
{
    int T, i, x, y;
    fin >> T;
    for(i = 0; i < T; i++)
    {
        fin >> x >> y;
        Euclid(x, y);
    }
    return 0;
}
