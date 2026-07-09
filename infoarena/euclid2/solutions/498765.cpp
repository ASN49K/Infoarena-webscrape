#include<iostream>
#include<fstream>
using namespace std;
int main() {
	int t,a,b,c,i;
	fstream f("euclid2.in", ios::in);
	fstream g("euclid2.out", ios::out);
	f>>t;
	for(i=1;i<=t;i++) {
		f>>a;
		f>>b;
		while(b!=0) {
			c=a%b;
			a=b;
			b=c; }
		g<<a<<endl;
	}
	f.close();
	g.close();
	return 0;
}