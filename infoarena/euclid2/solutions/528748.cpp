#include <fstream>

using namespace std;

int cmmdc(int,int);

int main () {
	ifstream fin;
	fin.open("euclid2.in");
	ofstream fout;
	fout.open("euclid2.out");
	int a,b,t;
	fin>>t;
	if (t>=1&&t<=100000) {	
	for (int i=1;i<=t;i++) {
			fin>>a>>b;
			fout<<cmmdc(a,b)<<"\n";
		}
	}
	fout.close();
	return 0;
}

int cmmdc(int a,int b) {
	if (!b) return a;
		return cmmdc(b,a%b);
}

