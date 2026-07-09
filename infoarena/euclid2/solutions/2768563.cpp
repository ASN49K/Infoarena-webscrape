//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int CMMDC(int a, int b) {
	int ans;
	while(a != b) {
		if(a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	ans = b;
	return ans;
}

int main() {
	int n, a, b;
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a >> b;
		cout << CMMDC(a, b) << endl;
	}		
}
