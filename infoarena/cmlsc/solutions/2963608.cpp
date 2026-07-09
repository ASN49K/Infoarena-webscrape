#include <bits/stdc++.h>

using namespace std;

ifstream in ("scmax.in");
ofstream out ("scmax.out");

const int dim = 1e5+1;
int n;
int a[dim], dp[dim], poz[dim], idx[dim];

int main()
{
    in >> n;
    for(int i=1; i<=n; i++)
        in >> a[i];

    int k = 1;
    dp[1] = a[1];

    for(int i=1; i<=n; i++)
    {
        if(a[i] > dp[k])
            dp[++k] = a[i], poz[i] = k;
        else
        {
            int l = 1, r = k, pos = k + 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;

                if(a[i] <= dp[mid])
                    pos = mid, r = mid - 1;
                else
                    l = mid + 1;
            }

            dp[pos] = a[i];
            poz[i] = pos;
        }
    }

    out << k << '\n';

    int j = n;
    for(int i = k; i > 0; i--)
    {
        while(poz[j] != i)
            j--;
        idx[i] = j;
    }

    for (int i=1; i<=k; i++)
        out << a[idx[i]] << ' ';

    return 0;
}
