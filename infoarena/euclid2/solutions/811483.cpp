#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{	
	int a,b,c,i,n;
    f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
		while (b)
		{c=a%b;
		a=b;
		b=c;}
		g<<a<<endl;
	}
	f.close();
	g.close();
	return 0;
}
