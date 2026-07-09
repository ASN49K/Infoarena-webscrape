#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int a,b;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << __gcd(a,b) << "\n";
    }
    return 0;
}
