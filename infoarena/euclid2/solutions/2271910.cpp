#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int N, A, B;
	cin >> N;
	while (N--) {
		cin >> A >> B;
		cout << __gcd(A,B) << endl;
	}
	
	return 0;
}
