// By Stefan Radu

#include <algorithm>
#include <iomanip>
#include <cassert>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
#include <set>

#ifdef INFOARENA
#include <fstream>
std::ifstream cin("nim.in");
std::ofstream cout("nim.out");
#else
#include <iostream>
#endif

using namespace std;

#define sz(x) (int)(x).size()

typedef pair < int, int > pii;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

int main() {

#ifdef STEF
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int t;
  cin >> t;

  while (t --) {

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; ++ i) {
      int k;
      cin >> k;
      sum ^= k;
    }

    cout << (sum ? "DA\n" : "NU\n");
  }
}
