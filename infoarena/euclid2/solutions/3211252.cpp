#include <bits/stdc++.h>
#include <unordered_map>
#define nmax 300005
#define MOD 666013
#define INF 2012345678
#define ll long long
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;

int GCD(int x, int y)
{
    int r;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int i, j;
    fin >> n;
    while (n--)
    {
        fin >> i >> j;
        fout << GCD(i, j) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}