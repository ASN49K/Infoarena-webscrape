#include<fstream.h>
unsigned t,i;
long unsigned a,b;
int main() {ifstream f("euclid2.in");
	    ofstream g("euclid2.out");
	    f>>t;
	    for(i=1;i<=t;i++){
	    f>>a;
	    f>>b;
	   while(a!=b){if(a>b) a=a-b;
		       else if(b>a) b=b-a;
		       }

		       g<<a<<"\n";}
		       }