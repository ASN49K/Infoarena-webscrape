#include <bits/stdc++.h>

#define FILES freopen("euclid2.in","r",stdin);\
              freopen("euclid2.out","w",stdout);

using namespace std;

int t, a, b;

int gcd(int a, int b)
{
    if(a > b)
        swap(a, b);
    while(b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
   FILES
   cin >> t;
   while(t--)
   {
       std::cin >> a >> b;
       std::cout << gcd(a, b) << '\n';
   }
}
