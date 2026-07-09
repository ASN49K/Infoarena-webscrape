#include <bits/stdc++.h>

using namespace std;

int main()  {
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    int n;
    cin >> n;
    while(n--)  {
        int a, b;
        cin >> a >> b;
        while(b)  {
            int r = a % b;
            a = b;
            b = r;
        }
        cout << a << "\n";
    }
    return 0;
}
