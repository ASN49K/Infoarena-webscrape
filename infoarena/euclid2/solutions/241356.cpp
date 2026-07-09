#include <fstream.h>
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
unsigned a,b,c,T,i;
for(i=1;i<=T;i++) {f>>a>>b;
while(b) { c=a%b;
	a=b;
	b=c;
	}
g<<a;}

f.close();g.close();
}

