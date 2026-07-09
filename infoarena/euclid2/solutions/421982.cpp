#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a,int b) {
	if(a%b==0)
		return b;
	else return cmmdc(b,a%b);
}
int main() {
	int T,i,m,n;
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
	