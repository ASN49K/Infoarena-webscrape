#include <fstream>
using namespace std;
int main()
{ 
	int t;
	ifstream f("nim.in");
	ofstream g("nim.out");
	f >> t;
	int n, x, s;
	while(t--) {
		f >> n;
		s = 0;
		while(n--) {
			f >> x; 
			s ^=x ;
		}
		g << (s > 0?"DA\n":"NU\n");
	}
}