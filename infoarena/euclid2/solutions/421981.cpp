#include <iostream>
#include <fstream>
using namespace std;

long cmmdc(long a,long b) {
	int r;
	while(b>0) {
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
		
int main() {
	int T,i;
	long m,n;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for(i=1;i<=T;i++) { 
		f>>m>>n;
		g<<cmmdc(m,n)<<endl;
	}
	f.close();
	g.close();
	return 0;
}
	