#include <bits/stdc++.h>
using namespace std;
int d, i, r, a, b, j, n;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> n;
    for(j = 1;j <= n;j++)
    {
        f >> a >> b;
        d = a;
        i = b;
        r = a % b;
        while(r != 0)
        {
            d = i;
            i = r;
            r = d % i;
        }
        g << i << "\n";
    }
    return 0;
}
