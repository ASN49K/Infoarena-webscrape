#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int a,b,t,x,y;
	f>>t>>a>>b;
	x=a;y=b;
	while(a!=b){
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	g<<a;
}
	
	