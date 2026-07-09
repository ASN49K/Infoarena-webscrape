using namespace std;

#include <iostream>
#include <fstream>
/*
int cmmdc(unsigned int a, unsigned int b){
	
}
*/
int main(){
	unsigned int a,b,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>a>>b;
	f.close();
		/*
	if(a<b)	{
		a=a+b;
	    b=a-b;
		a=a-b;
	}
	*/
	r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	g<<b<<"\n";
	g.close();
	// cout<<cmmdc(a,b);
	
	return 0;
}
