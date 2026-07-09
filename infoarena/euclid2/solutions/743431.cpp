#include <fstream>

using namespace std;

int cmmdc(int a, int b){
	while(a != b)
		if(a>b)
			a-=b;
		else
			b-=a;
	return a;
}

int main(){
	int n, a, b;
	ifstream fpi("euclid2.in");
	ofstream fpo("euclid2.out");
	fpi>>n;
	while(n>0){
		fpi>>a>>b;
		fpo<<cmmdc(a, b)<<"\n";
		n--;
	}
	fpi.close();
	fpo.close();
	return 0;
}