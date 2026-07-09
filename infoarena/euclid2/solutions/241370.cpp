#include <fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void main()
{
unsigned a,b,c,T,i;f>>T;
for(i=1;i<=T;i++) {f>>a>>b;
while(b) { c=a%b;
	a=b;
	b=c;
	}g<<a<<endl;}
	f.close();g.close();


}

