#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return(gcd(b, a%b));
}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << "\n";
    }

    return 0;
}
