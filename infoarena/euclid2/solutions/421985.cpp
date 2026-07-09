#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a,int b) {
	int r;
	while(b) {
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main() {
	int T,i,a,b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for(i=1;i<=T;i++) { 
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
	}
	f.close();
	g.close();
	return 0;
}
	