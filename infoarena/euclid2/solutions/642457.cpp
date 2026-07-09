#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(int a, int b) {
	int c;
	while(b!=0) {
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main() {
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t,a,b;
	f>>t;
	for(int i=0;i<t;i++) {
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}
