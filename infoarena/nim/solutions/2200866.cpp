#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("nim.in");
	ofstream cout("nim.out");
	int x,t,n;
	cin >> t;
	while(t--){
		cin >> n;
		int ans = 0;
		while(n--){
			cin >> x;
			ans ^= x;
		}
		cout << (ans ? "DA\n" : "NU\n");
	}
}

