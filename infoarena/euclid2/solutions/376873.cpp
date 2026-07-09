#include <iostream> 
#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
	int r;
	while((r=a%b)!=0)
	{
		a=b;
		b=r;
	}
	return b;
}
int main()
{
	int a,i,b,c;
	//freopen("euclid2.in","r",stdin);
	//freopen("euclid2.out","w",stdout);
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);
	f>>a;
	for(i=0;i<a;++i)
	{
		f>>b>>c;
		g<<cmmdc(b,c)<<endl;
	}
	return 0;
}