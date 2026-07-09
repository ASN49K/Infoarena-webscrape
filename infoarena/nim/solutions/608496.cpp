#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("nim.in");
	ofstream g("nim.out");
	int t,n,rez,x;
	for(f>>t;t--;) {
		f>>n;rez=0;
		for(int i=1; i<=n; ++i) {
			f>>x; rez^=x;
		}
		if(rez) g<<"DA\n";
		else g<<"NU\n";
	}
	return 0;
}