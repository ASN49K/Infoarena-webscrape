/*
    Keep It Simple!
*/

#include <fstream>
#include <vector>
#include <list>
#include <stack>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int gcd(int x, int y)
{
    if (!y) return x;
    return gcd(y,x%y);
}

void Solve()
{
    int T, x, y;
    fin >> T;
    while (T--)
    {
        fin >> x >> y;
        fout << gcd(x,y) << '\n';
    }
}

int main()
{
    Solve();
    return 0;
}
