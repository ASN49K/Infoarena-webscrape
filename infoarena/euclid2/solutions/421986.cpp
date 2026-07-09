#include <iostream>
#include <fstream>
using namespace std;
int T,a,b;
int euclid(int a,int b) {
	int r;
	while(b) {
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main() {
	int i;
	ifstream f("euclid2.in");
	f>>T;
	ofstream g("euclid2.out");
	for(i=1;i<=T;i++) { 
		f>>a>>b;
		g<<euclid(a,b)<<endl;
	}
	f.close();
	g.close();
	return 0;
}
	