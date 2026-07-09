#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    ios::sync_with_stdio(false);
    int N, a,b;
    cin >> N;
    while(N --) {
        cin >> a >> b;
        cout << gcd(a, b) << "\n";
        ///cout << __gcd(a, b) << "\n";
    }
    return 0;
}
