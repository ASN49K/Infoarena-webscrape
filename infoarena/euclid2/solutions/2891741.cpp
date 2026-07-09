#include <fstream>
using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int euclid(int a , int b) {
	if(b == 0) {
		return a;
	}
	return euclid(b, a % b);
}


int main() {
	int n;

	cin >> n;

	while(n--) {
		int a, b;
		cin >> a >> b;
		cout << euclid(a, b) << '\n';
	}
	cin.close();
	cout.close();	
	return 0;
}
