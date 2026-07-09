#include <bits/stdc++.h>
using namespace std;

int t, a, b;
int main(){
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> a >> b;
		while (a != b){
			if (a > b){
				a -= b;
			}
			if (a < b){
				b -= a;
			}
		}
		cout << a;
	}
	return 0;
}