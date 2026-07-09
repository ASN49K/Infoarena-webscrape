
#include <fstream>
using namespace std;



inline long cmmdc(long a, long b){
	long t;
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
	long T,a,b;
	ifs>>T;
	while(T--){
		ifs>>a>>b;
		ofs<<cmmdc(a,b)<<endl;
	}
	return 0;
}