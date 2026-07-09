#include<fstream.h>
long unsigned t,i,a,b,c;
int main() {ifstream f("euclid2.in");
	    ofstream g("euclid2.out");
	    f>>t;
	    for(i=1;i<=t;i++){
	    f>>a;
	    f>>b;
	   while(b){c=a%b;a=b;b=c;}

		       g<<a<<"\n";}
                       return 0;
		       }