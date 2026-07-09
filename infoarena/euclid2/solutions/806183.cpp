#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int gcd(int a,int b){
	if(!b)
		return a;
	return gcd(b,a%b);
}

int main(){
	int t,x,y;
	in>>t;
	while(t--){
		in>>x>>y;
		out<<gcd(x,y)<<"\n";
	}
	return 0;
}