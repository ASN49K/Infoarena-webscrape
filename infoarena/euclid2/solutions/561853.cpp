#include<iostream.h>
#include<fstream.h>
int cmmdc(int a, int b)
{
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}
 int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long a,b,T,i;
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
	}
	f.close();
	g.close();
	
	return 0;
 }
