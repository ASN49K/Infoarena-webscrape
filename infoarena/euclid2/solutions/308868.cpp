#include <fstream.h>

int a,b; 

void citire(){
	ifstream fi("cmmdc.in");
	fi>>a;
	fi>>b;
	fi.close();
}

int euclid(int a,int b){
	int r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
			 
			 

void afisare(){
	ofstream fo("cmmdc.out");
	fo<<euclid(a,b);
	fo.close();
}

int main(){
	citire();
	afisare();
	return 0;
}