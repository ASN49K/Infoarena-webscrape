
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")

#define input "euclid2.in"
#define output "euclid2.out"

using namespace std;


int euclid(int a, int b)
{
    if (b == 0)
        return a;
    return euclid(b, a % b);
}

main()
{
    freopen(input, "r", stdin);
    freopen(output, "wt", stdout);

    int q, x, y;
    cin >> q;

    while (q)
    {
        q--;
        cin >> x >> y;
        cout << euclid(x, y) << "\n";
    }

    return 0;
}
