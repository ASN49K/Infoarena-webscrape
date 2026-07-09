#include <bits/stdc++.h>

using namespace std;

int xorSum(int arr[], int n) {
    int sxor = arr[0];
    for(int i = 1; i < n; ++i)
        sxor ^= arr[i];

    return sxor;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);

    int t;
    cin >> t;
    for(; t; t--) {
        int n;
        cin >> n;
        int gramezi[n + 5];
        for(int i = 0; i < n; ++i)
            cin >> gramezi[i];

        if(xorSum(gramezi, n))
            cout << "DA\n";
        else
            cout << "NU\n";
    }

    return 0;
}
