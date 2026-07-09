// Author: Tanasescu Andrei-Rares
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <iomanip>
#include <vector>
#include <cassert>

#pragma GCC optimize("O3")

#define fi first
#define se second
#define pb push_back
#define pf push_front

using namespace std;

ifstream fin ("nim.in");
ofstream fout ("nim.out");

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll Nmax=1e6+5, inf=1e9+5;

int t, n, s, p;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fin>>t;
    while (t--){
        fin>>n;
        for (int i=0; i<n; i++){
            fin>>p;
            s^=p;
        }
        if (s==0)
            fout<<"NU\n";
        else fout<<"DA\n";
    }

    return 0;
}