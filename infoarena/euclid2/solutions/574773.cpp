#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long cmmdc(long a, long b){
	if (b == 0)
		return a;
	else
		return cmmdc(b,a%b);
}

int main(){
	int n,i;
	long a,b;
	fin>>n;
	for (i=0; i<n; ++i){
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
	}
	fout.close();
	fin.close();
	return 0;
}
