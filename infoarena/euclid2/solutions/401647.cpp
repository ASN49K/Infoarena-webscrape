#include<fstream>
//#include<iostream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (int a, int b) {
	int cop;
	while (b!=0) {
		cop=b;
		b=a%b;
		a=cop; }
	return a;}

int main () {
	int t,a,b;
	fin>>t;
	for (int i=0;i<t;i++) {
		fin>>a>>b;
		if (a>b) fout<<cmmdc(a,b)<<'\n';
			else fout<<cmmdc(b,a)<<'\n';
}
fin.close(); fout.close();}