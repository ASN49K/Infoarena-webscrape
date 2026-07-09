#include <fstream>
using namespace std;
int main() {
	ifstream f("nim.in");
	ofstream g("nim.out");
	int x,t,n,b,l,i;
	f>>t;
	for (l=1; l<=t; l++) {
		f>>n;
		f>>x;
		for (i=2; i<=n; i++) {
			f>>b;
			x=x ^ b;
		}
		if (x)
			g<<"DA"<<'\n';
		else g<<"NU"<<'\n';
	}
	g.close();
	return 0;
}
