//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int CMMDC(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return CMMDC(b , a % b);
	}
}

int main() {
	int n, a, b, c;
	cin >> n;
	for(int i = 0;i<n;i++) {
		cin >> a >> b;
		c = CMMDC(a, b);
		cout << c << endl;	
	}		
}
