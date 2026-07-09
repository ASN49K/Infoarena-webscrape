#include<fstream>
int cmmdc(int a,int b)
{
	int r;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}
	while(r!=0);
	return a;
}
int main ()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int T,a,b;
	f>>T;
	for(int i=1;i<=T;++i)
	{
		f>>a>>b;
		g<<cmmdc(a,b)<<"\n";
	}
	f.close();
	g.close();
	return 0;
}