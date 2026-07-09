//#include <iostream>
#include <fstream>
using namespace std;

ifstream cin("rezolvare.in");
ofstream cout("rezolvare.out");

int CMMDC(int a, int b) {
	if(b == 0 ) {
		return a; 
	}
	else {
		return CMMDC(b, a%b);
	}
}

int main() {
	int n, a, b;
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a >> b;
		cout << CMMDC(a, b) << endl;
	}		
}
