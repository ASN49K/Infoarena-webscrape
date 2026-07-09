#include <fstream>

using namespace std;

int main () {

	ifstream fin;
	fin.open("euclid2.in");
	ofstream fout;
	fout.open("euclid2.out");
	int a[99999],b[99999],c,t,i;
	fin>>t;
	for (i=0;i<=--t;i++) {
	fin>>a[i]>>b[i];
	}
	for (i=0;b!=0,i<=--t;i++) {
		c=a[i]%b[i];
		a[i]=b[i];
		b[i]=c;
		fout<<a[i];
	}
	fout.close();
	return 0;
}