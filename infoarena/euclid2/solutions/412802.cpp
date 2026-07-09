#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(int a, int b) {
	if(a%b==0) return b;
	else return cmmdc(b,a%b);
}
int main() {
	int a,b,i,t;
	ifstream f("euclid2.in");
	f>>t;
	ofstream g("euclid2.out");
	for(i=1;i<=t;i++)
	{ f>>a>>b;
	  g<<cmmdc(a,b)<<endl;
	}
	f.close();
	g.close();
	return 0;
}