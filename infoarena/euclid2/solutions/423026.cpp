#include<fstream.h>

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
	int T, a, b;
	ifstream f("euclid2.in");
	f>>T;
	int i;
	ofstream g("euclid2.out");
	for(i=0;i<T;i++){
		f>>a>>b;
		g<<cmmdc(a, b)<<endl;
	}
	f.close();
	g.close();
	return 0;
}
