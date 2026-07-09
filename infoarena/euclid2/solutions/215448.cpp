#include<fstream.h>
int euclid(int a,int b,int r)
{
	if(r==0) return b;
	else 
	{
	    a=b;
		b=r;
		return euclid(a,b,a%b);
	}
}
int main()
{
	ifstream f("euclid2.in"); 
	ofstream g("euclid2.out");
	int a,b,i=1,n;
	f>>n;
	while(i<=n)
	{
		f>>a>>b;
		g<<euclid(a,b,a%b)<<endl;
	}
	f.close();
	g.close();
	return 0;
}
