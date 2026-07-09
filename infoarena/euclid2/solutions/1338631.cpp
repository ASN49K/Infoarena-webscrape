#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T,a,b;

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,b%a);
}

int main(){
	in>>T;
	for(int i=1;i<=T;i++){
		in>>a>>b;
		out<<gcd(a,b);
	}
	return 0;
}