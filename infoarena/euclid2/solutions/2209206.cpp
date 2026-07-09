#include <bits/stdc++.h>

#define rc(x) return cout<<x<<endl,0

using namespace std;

int t,a,b,m,n,r;
int k = INT_MAX;

int main(){
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> a >> b;
		n = min(a,b);
		m = max(a,b);
		while(1){
			r = m % n;
			if(r == 0){
				cout << n << '\n';
				break;
			}
			m = n;
			n = r;
		}
	}
	return 0;
}