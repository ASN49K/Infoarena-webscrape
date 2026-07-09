#include<fstream>
using namespace std;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
int t,a,b,r,i;
int main()
{
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>a>>b;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<" ";
	}
	return 0;
}