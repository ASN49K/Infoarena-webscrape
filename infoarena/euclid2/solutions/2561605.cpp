
#include <bits/stdc++.h>

#define input "euclid2.in"
#define output "euclid2.out"

using namespace std;

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
        cout << __gcd(x, y) << "\n";
    }

    return 0;
}
