#include <fstream>
#include <iostream>

#define FIN "euclid2.in"
#define FOUT "euclid2.out"

using namespace std;

namespace Math {

int euclid(int a, int b) {

int r;
while(b){
	r = a%b;
	a = b;
	b = r;
}
return a;
}
}

int main(int argc, char const *argv[]) {
	int a,b,T;
	
	ifstream fin(FIN);
	ofstream fout(FOUT);
	
	for(fin>>T; T; T--){
		fin>>a>>b;
		fout<<Math::euclid(a,b)<<"\n";
	}
	return 0;
}
