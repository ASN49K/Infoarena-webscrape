#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,i;
int main() {
	f>>n;
	for (i=1;i<=n;i++) {
		f>>a>>b;
		while (a!=0&&b!=0) {
			if (a>b) a=a%b;
			else if (b>a) b=b%a;
		}
		if (a!=0) g<<a<<"\n";
		else g<<b<<"\n";
	}
}
