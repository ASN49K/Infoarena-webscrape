#include <fstream.h>

int a,b;

void citire(){
	ifstream fi("euclid.in");
	fi>>a;
	fi>>b;
	fi.close();
}

int euclid(int a,int b){
	int r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

void afisare(){
	ofstream fo("euclid.out");
	fo<<euclid(a,b);
	fo.close();
}

int main(){
	citire();
	afisare();
	return 0;
}

