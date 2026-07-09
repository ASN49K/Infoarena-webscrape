#include <iostream>
#include <fstream>
using namespace std;

int T,A,B;

int imp(int a, int b){
	if(!b) return a;
	return imp(b,b%a);
}

int main(){
	ifstream f("uclid2.in");
	ofstream g("uclid2.out");
	
	f>>T;
	
	for (int i=1;i<=T;i++){
		f>>A>>B;
		g<<imp(A,B)<<endl;
	}
	f.close();
	g.close();
}