#include<fstream.h>
unsigned t;
long unsigned a,b;
int main() {ifstream f("euclid2.in");
	    ofstream g("euclid2.out");
	    f>>t;
	    while(t!=0){
	    f>>a>>b;
	   while(a!=b){if(a>b) a=a-b;
		       else if(b>a) b=b-a;
		       }t--;

		       g<<a<<"\n";}
                       }