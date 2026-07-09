#include <iostream>
#include <fstream>
using namespace std;

int T,A,B;
ifstream f("uclid2.in");
ofstream g("uclid2.out");
	
int imp(int a, int b){
	if(!b) return a;
	else if (a<b) return imp(a, b-a);
		else return imp(a-b,b);
}

int main(){
	f>>T;
	for (int i=1;i<=T;i++){
		f>>A>>B;
		g<<imp(A,B)<<endl;
	}
}