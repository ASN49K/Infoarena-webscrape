#include <bits/stdc++.h>

#define FILES freopen("euclid2.in","r",stdin);\
              freopen("euclid2.out","w",stdout);

using namespace std;

int t, a, b;

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   FILES
   cin >> t;
   while(t--)
   {
       std::cin >> a >> b;
       std::cout << __gcd(a, b) << '\n';
   }
}
