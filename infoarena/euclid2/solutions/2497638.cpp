#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");

int T;
long long a,b;

int main()
{

    freopen("euclid2.out", "w", stdout);

    fin >> T;

    for(;T;T--)
    {
        fin >> a >> b;
        printf("%d\n",__gcd(a,b));
    }

    return 0;

}
