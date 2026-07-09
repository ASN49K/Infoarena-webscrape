#include<fstream>
using namespace std;

int main()
{
	fstream f("euclid2.in",ios::in);
	fstream g("euclid2.out",ios::out);
	unsigned a,b,r,n,i;
	f>>n;
	i=0;
	while(i<n)
	{
		f>>a>>b;
		if(a<b)
		{
			unsigned aux=a;
			a=b;
			b=aux;
		}
		
		while(a%b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<endl;
		i++;
	}
	f.close();
	g.close();
	return 0;
}