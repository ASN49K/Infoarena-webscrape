#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int t, a, b;

int euclid(int x, int y)
{
    if(!y) return x;
    return euclid(y, x % y);
}
int main()
{
    fin >> t;
    for(int  i = 1; i <= t; i++)
    {
        fin >> a >> b;
        fout << euclid(a, b) << '\n';
    }
    return 0;
}
