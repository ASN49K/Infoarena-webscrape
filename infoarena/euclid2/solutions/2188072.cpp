#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int a,b,r,i,n;
	f>>n;
	for(i=0; i<=n; i++) {
		f>>a>>b;
		r=a%b;
		while(r!=0){
			a=b;
			b=r;
			r=a%b;
		}
		g<<b<<endl;
}
return 0;
}