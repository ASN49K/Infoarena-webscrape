#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int euclid(int x, int y)    {
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    return euclid(y, x % y);
}
 
int main()  {
    
   freopen("euclid2.in", "r", stdin);
   freopen("euclid2.out", "w", stdout);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << euclid(a, b) << '\n';
    }
    return 0;
}
