#include<iostream>
#include<fstream>
using namespace std;
int T;
int euclid(int a, int b){
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
	ifstream f("euclid.in");
	ofstream g("euclid.out");
	f>>T;
	for(int i=1;i<=T;i++){
		f>>a>>b;
		g<<euclid(a,b)<<'\n';
	}
}