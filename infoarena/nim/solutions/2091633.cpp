#include <bits/stdc++.h>
#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define V vector<int>
#define VP vector<pair<int, int> >
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#ifdef _WIN32
#include <windows.h>
#define print(x) PRINT(x, #x)
template<typename T> inline const void PRINT(T VARIABLE, string NAME)
{
#ifndef ONLINE_JUDGE /// ONLINE_JUDGE IS DEFINED ON CODEFORCES
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    cerr << NAME << " = " << VARIABLE;
    SetConsoleTextAttribute(hConsole, 7);
    cerr << '\n';
#endif
}
#else
#define print(x) 0
#endif
typedef long long ll;
typedef unsigned long long ull;
const ll INFLL = 2 * (ll)1e18 + 100;
const int INFINT = 2 * (int)1e9 + 100;
const double PI = atan(1) * 4;
const double EPS = 1e-12;
const int SEED = 1e3 + 7;

const int MOD = 1e9 + 7; /// careful here (7 or 9, 66.. etc)
const int NMAX = 250000 + 5;

ifstream fin("nim.in");
ofstream fout("nim.out");
#define cin fin
#define cout fout

int main()
{
    FASTIO;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int s = 0;
        for1(i, n)
        {
            int a;
            cin >> a;
            s ^= a;
        }
        if(s) cout << "DA\n";
        else cout << "NU\n";
    }

    return 0;
}
