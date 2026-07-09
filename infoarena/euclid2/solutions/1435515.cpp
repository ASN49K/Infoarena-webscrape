#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

int euclid_f(int a, int b){
	int r = a % b;
	while(r){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main(){
	
	int a,b,n;
	int i;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(i = 0 ; i < n ; i ++){
		f>>a>>b;
		g<<euclid_f(a,b)<<endl;
	}

	f.close();
	g.close();
	return 0;
}