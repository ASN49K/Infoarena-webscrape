#include <iostream>
#include <fstream>
using namespace std;

int T,A,B;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
	
int imp(int a, int b){
	if(!b) return a;
	else return imp(b,a%b);
}

int main(){
	f>>T;
	for (int i=1;i<=T;i++){
		f>>A>>B;
		g<<imp(A,B)<<endl;
	}
}