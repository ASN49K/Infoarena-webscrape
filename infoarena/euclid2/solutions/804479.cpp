#include <fstream>
using namespace std;

unsigned int cmmdc(unsigned int a,unsigned int b){
	unsigned int  t;
	if(a>b){
		t=a;
		a=b;
		b=t;
	}
	while(t=a%b){
		a=b;
		b=t;
	}
	return b;
}


int main(){
	ifstream ifs("euclid2.in");
	ofstream ofs("euclid2.out");
	unsigned int T;
	ifs>>T;
	while(T--){
		unsigned int a,b;
		ifs>>a>>b;
		ofs<<cmmdc(a,b)<<"\n";
	}
	return 0;
}