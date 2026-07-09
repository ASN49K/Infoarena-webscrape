#include <fstream>

using namespace std;

const char InFile[]="euclid2.in";
const char OutFile[]="euclid2.out";

unsigned long int a,b,t;

unsigned long int cmmdc(unsigned long int a,unsigned long int b){
	unsigned long int r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main(){
	ofstream fout(OutFile);
	ifstream fin(InFile);
	fin>>t;
	for(register unsigned long int i=0;i<t;++i){
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
	}
	fin.close();
	fout.close();
}
