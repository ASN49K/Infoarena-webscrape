#include <iostream>
using namespace std;
#include <fstream>

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b,i;

int euclid(int a, int b){
	if(b == 0)
		return a;
	else
		return (b, b%a);
}

int main(){
	f>>T;
	for(i=1; i<=T; i++){
		f>>a>>b;
		g<<euclid(a,b);
	}
	f.close();
	g.close();
}
