#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <algorithm>
#define x first
#define y second

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int euclid(int a, int b)
{
    int t;
    while(b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int n, i, x, y;
int main()
{
    in.sync_with_stdio(false);
    out.sync_with_stdio(false);
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>x>>y;
        out<<euclid(x,y)<<'\n';
    }

    return 0;
}
