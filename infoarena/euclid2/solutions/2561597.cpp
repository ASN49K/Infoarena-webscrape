#define Middle School
#include <bits/stdc++.h>
#pragma GCC optimize ("O3")

#define input "euclid2.in"
#define output "euclid2.out"

typedef std::vector<int> VI;
typedef long long ll;

const ll lul = 1e7;

using namespace std;

int q, x, y;

int Euclid(int a, int b)
{
    if (b == 0)
        return a;
    return Euclid(b, a % b);
}

main()
{
    freopen(input, "r", stdin);
    freopen(output, "wt", stdout);

    cin >> q;

    while (q--)
    {
        cin >> x >> y;
        cout << Euclid(x, y) << "\n";
    }

    return 0;
}
