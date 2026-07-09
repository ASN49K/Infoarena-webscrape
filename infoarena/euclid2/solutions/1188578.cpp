#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2in");
ofstream g("euclid2.out");

int cmmdc(int a, int b){
	
	int c;
	
	while(b){
		c=a%b;
		a=b;
		b=c;
	}
	
	return a;
}

int main(){
	
	int a, b;
	
	f>>a>>b;
	
	g<<cmmdc(a,b);
	
	return 0;
}
