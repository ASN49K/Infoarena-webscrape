#include<iostream>
#include<fstream>
using namespace std;
int gcd(int a,int b){
	return (b==0?a:gcd(b,a%b));
}
int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int T,a,b;
	in>>T;
	while(T--){
		in>>a>>b;
		out<<gcd(a,b)<<'\n';
	}
	return 0;
}