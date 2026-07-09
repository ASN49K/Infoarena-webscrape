#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a, int b) {
   if (b == 0)
      return a;

   while(b!=0) {
      int t = a % b;
      a = b;
      b = t;
   }

   return a;
}

void solve() {
   int a, b;
   f >> a >> b;

   g << cmmdc(a,b) << '\n';

}
int main() {
   int q;
   f >> q;
   while (q--) {
      solve();
   }
   return 0;
}