#include <fstream>
using namespace std;

int euclid_cmmdc(int a, int b) {
	if (!b) return a;
	return euclid_cmmdc(b, a%b);
}

int main() {
	int n, a, b, i;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	f>>n;
	for(i=0; i<n; i++) {
		f>>a>>b;
		if(a>b) g<<euclid_cmmdc(a,b)<<"\n";
		else if (a<b) g<<euclid_cmmdc(b,a)<<"\n";
		else g<<a<<"\n";
	}
}
