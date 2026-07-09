#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b, ct;


ll cmmdc(ll a, ll b){
    while(b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main()
{
	cin >> n;

	for(int i = 1; i <= n; i++){
	    cin >> a >> b;
        cout << cmmdc(a, b) << endl;

	}


	return 0;
}
