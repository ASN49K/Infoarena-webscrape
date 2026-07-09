#include<iostream>
using namespace std;

#define infile "euclid2.in"
#define outfile "euclid2.out"

inline int cmmdc(int a, int b){
	if(!b)
		return a;
	return cmmdc(b, a % b);
}

int main(){
	int T, a, b;
	
	for(cin >> T; T; --T){
		cin >> a >> b;
		cout << cmmdc(a, b) << '\n';
	}
	
	return 0;
}