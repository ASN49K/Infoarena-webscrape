#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main ()
{
	int T,a,b,i;
	f>>T;
	for(i=0;i<T;i++)
	{
		f>>a>>b;
		while(a!=b)
			if(a>b)
				a=a-b;
			else
				b=b-a;
		g<<a<<endl;
	}
	g.close();
	return 0;
}
