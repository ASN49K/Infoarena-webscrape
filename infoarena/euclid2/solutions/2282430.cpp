#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");



int a,b,e;


int cmmdc(int a,int b) {
	if (b==0)
		return a;
	return cmmdc(b,a%b);
}


int main() {
	fin>>e;
	while (e--)
    {
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
	}


	return 0;


}
