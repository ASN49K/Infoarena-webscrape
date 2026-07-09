#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define int long long
using namespace std;
const string TASK("euclid2");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 2e5 + 9;

int a, b, c;

void euclid(int a, int b, int& x, int& y)
{
    if(!b)x = 1, y = 0;
    else
    {
        int xa, ya;
        euclid(b, a % b, xa, ya);
        x = ya;
        y = xa - ya * (a / b);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t --)
    {
        cin >> a >> b;
        cout << __gcd(a, b) << '\n';
    }
    return 0;
}
