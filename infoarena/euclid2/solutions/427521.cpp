#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b) {
	int r;
	while (b!=0) {
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main () { 
	int a,b,n;
	ifstream ifile ("euclid2.in");
	ofstream outfile ("euclid2.out");
	ifile >> n;
	for (int i=1;i<=n;i++) {
		ifile >> a >> b;
		outfile << cmmdc(a,b) << "\n";
	}
	outfile.close();
	ifile.close();
	return 0;
}