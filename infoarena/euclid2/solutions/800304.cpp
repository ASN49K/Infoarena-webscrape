#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs("euclid2.in");
ofstream ofs("euclid2.out");

inline int cmmdc(int a,int b){
	if(b==0)
		return a;
	else
		return cmmdc(b,a%b);
}


int main(){
	int T,a,b;
	ifs>>T;
	while(T--){
		ifs>>a>>b;
		ofs<<cmmdc(a,b)<<endl;
	}
	return 0;
}