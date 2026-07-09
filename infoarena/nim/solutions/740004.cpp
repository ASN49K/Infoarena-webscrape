#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream f("nim.in");
	ofstream g("nim.out");
	
	int t, n, i, nr, suma;
	f>>t;
	for(int k=1; k<=t; k++) {
		f>>n;
		f>>suma;
		for(i=2; i<=n; i++) {
			f>>nr;
			suma^=nr;
		}
		if(suma!=0) g<<"DA\n";
		else g<<"NU\n";
	}
	
	f.close();
	g.close();
	
	return 0;
}