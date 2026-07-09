#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

long euclid_f(long a, long b){
	long r = a % b;
	while(b){
		r = b;
		b = a % b;
		a = r;
		
	}
	return a;
}

int main(){
	
	long a,b,n;
	int i;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i = 0 ; i < n ; i ++){
		f>>a>>b;
		g<<euclid_f(a,b)<<"\n";
	}

	f.close();
	g.close();
	return 0;
}