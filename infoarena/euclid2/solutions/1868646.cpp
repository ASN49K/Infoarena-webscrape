#include <bits/stdc++.h>
using namespace std;

long long gcd (long long a, long long b) {
    if (b == 0) {
	return a;
    }
    return gcd (b, b % a);
}

int main() {

    ifstream cin ("euclid2.in");
    ofstream cout ("euclid2.out");

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
	long long a, b; cin >> a >> b;
	cout << gcd (a, b) << "\n";
    }
    
    return 0;
}
