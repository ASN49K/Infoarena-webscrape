#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main() {
	int t,i,x,a,b,j;
	fin>>t;
	for (i=1;i<=t;++i) {
	fin>>a>>b;
	x=min(a,b);
	for (j=x; j; j--) 
		if (a%j==0 && b%j==0) { 
		fout<<j;
		break;
		} 
	}
	return 0;
    } 

