#include<fstream>
#include<iostream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int cmmdc (int a, int b) {
	while (a!=b)
		if (a>b) a-=b;
			else b-=a;
	return a;}

int main () {
	int t,a,b;
	fin>>t;
	for (int i=0;i<t;i++) {
		fin>>a>>b;
		fout<<cmmdc(a,b)<<'\n';
}
fin.close(); fout.close();}