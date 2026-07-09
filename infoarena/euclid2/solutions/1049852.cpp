#include <iostream>
using namespace std;
#include <fstream>

ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,i;
long long a,b;

long long euclid(long long a, long long b){
	if(b == 0)
		return a;
	else
		return euclid(b, a%b);
}

int main(){
	f>>T;
	for(i=1; i<=T; i++){
		f>>a>>b;
		g<<euclid(a,b)<<endl;
	}
	f.close();
	g.close();
}
