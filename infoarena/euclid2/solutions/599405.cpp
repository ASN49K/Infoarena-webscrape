#include <fstream.h>
unsigned int r,a,b,n,i;
main(void){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	f.close();
	for(i=1; i<=n; i++)
	{
		f>>a>>b;
		while(b!=0)
		{
			r=a%b;
			a=b;b=r;
		}
		g<<a<<"\n";
	}
	g.close();
	return 0;
}