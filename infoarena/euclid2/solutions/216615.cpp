#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	int a,b,n,i,c;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for (i=0;i<n;i++) {
	f>>a>>b;
	while(b){  
    c=a%b;  
     a=b;  
     b=c;  
	}
	g<<a<<"\n";
	}
	f.close();
	g.close();
	return 0;
}