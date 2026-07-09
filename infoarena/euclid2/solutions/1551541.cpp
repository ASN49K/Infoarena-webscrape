#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b) {
	int r;
	
	while (b) {
		r=a%b;
		a=b;
		b=r;
	}
	
	return a;
	
}

int main() {
	ifstream in;
	ofstream out;
	int a,b,t;
	in.open ("cmmdc.in");
	out.open ("cmmdc.out");
	in>>t;
	for (int x=0; x<t; x++){
		in>>a>>b;
		out<<cmmdc(a,b)<<"\n";
	}
	
	
}


