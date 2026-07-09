#include <fstream>
using namespace std;

fstream f("input.in",ios::in);
fstream g("output.out",ios::out);

int cmmdc(int a, int b) {
	int r;
	do {
		r=a%b;
		a=b;
		b=r;
	} while (r!=0);
	return a;
}

int main () {
	int n,a,b;
	f>>n;
	for(int i=1;i<=n;i++) {
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
	}
	f.close();
	g.close();
return 0;
}