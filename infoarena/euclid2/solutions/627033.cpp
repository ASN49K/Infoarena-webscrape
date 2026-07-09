#include<iostream>
#include<fstream>
using namespace std;
int main (){
	int T,a,b;
	ifstream f("euclid.in");
	ofstream g("euclid2.out");
	f>>T;
	while(f){
		f>>a>>b;
		while(a!=b)
			if(a>b)
				a=a/b;
			else
				b=b/a;
		g<<a;
	}
	f.close();
	g.close();

}