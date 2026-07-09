using namespace std;

#include <iostream>
#include <fstream>
/*
int cmmdc(unsigned int a, unsigned int b){
	
}
*/
unsigned int eu(unsigned int a, unsigned int b){
	unsigned int r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main(){
	unsigned int t,a,b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>t;
		/*
	if(a<b)	{
		a=a+b;
	    b=a-b;
		a=a-b;
	}
	*/
	while(t--)
	{
		f>>a>>b;
		g<<eu(a,b)<<"\n";
	}
	f.close();
	g.close();
	// cout<<cmmdc(a,b);
	
	return 0;
}
