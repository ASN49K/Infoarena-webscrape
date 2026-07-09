#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

int euclid (int a, int b) {
  if (!b) return a;

  return euclid (b, a%b);
}

int main() {
  #ifdef BLAT
    freopen("stdin", "r", stdin);
    freopen("stderr", "w", stderr);
  #else 
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
  #endif

  cin.tie(0)->sync_with_stdio(0);

  srand(time(NULL));

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    cout << euclid(a, b) << '\n';  
  }
  return 0;
}