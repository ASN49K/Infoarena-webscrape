
#include <bits/stdc++.h>
//#pragma GCC optimize ("03")
#define FastIO ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0)
#define FILES freopen("nim.in" , "r" , stdin) , freopen("nim.out" , "w" , stdout)

using namespace std;

int t , n , x;

signed main()
{
	#ifndef ONLINE_JUDGE
		FastIO , FILES;
	#endif

    cin >> t;

    while(t--)
    {
        cin >> n;

        int s = 0;

        for(int i = 1 ; i <= n ; i++)
            cin >> x , s ^= x;

        cout << (s == 0 ? "NU\n" : "DA\n");
    }

    return 0;
}
