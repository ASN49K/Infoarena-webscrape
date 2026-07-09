#include <fstream>
using namespace std;
unsigned long int a,b,T,x,c;
int main () {
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	while(T!=0) {
		f>>a>>b;
		T--;
		if(a<b) {
			x=a;
			a=b;
			b=x;
		}
		while(b!=0) {
		c=a%b;
		a=b;
		b=c;}
		g<<a<<endl;
	}
	return 0;
}
	