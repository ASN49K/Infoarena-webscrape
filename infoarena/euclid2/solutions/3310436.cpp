#include<fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a, int b){
	int c;
	while(b) {
		c = a%b;
		a = b;
		b = c;
	}
	return a;
}

void solve() {
	int a, b;
	in>>a>>b;
	out<<gcd(a,b)<<'\n';
}

int main() {
	int t;
	in >> t;
	while(t--) solve();
	return 0;
}
