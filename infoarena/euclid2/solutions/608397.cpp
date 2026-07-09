#include <fstream.h>
long long T,a,b,i;

int euclid(int x, int y){
	if (!y)
		return x;
	return euclid(y,x%y);
}

int main(){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for (i=0;i<T;i++){
		f>>a>>b;
		g<<euclid(a,b)<<"\n";
	}
}