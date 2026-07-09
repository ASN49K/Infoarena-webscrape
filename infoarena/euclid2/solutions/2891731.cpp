//#include <iostream>
#include <fstream>
#include <utility>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid(int a , int b) {
	if(a == 0) {
		return b;
	}
	return euclid(b % a, a);
}


int main() {
	int n;

	cin >> n;

	while(n--) {
		int a, b;
		cin >> a >> b;
		cout << euclid(a, b) << endl;
	}	
	
}
