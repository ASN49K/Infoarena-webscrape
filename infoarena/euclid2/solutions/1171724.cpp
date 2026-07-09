#include <fstream>
using namespace std;

int main()
{
	unsigned x,a,b,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	for(f>>x;x>0;x--)
	{
		f>>a>>b;
		while(a!=b)
			if(a>b)
				a-=b;
			else
				b-=a;
		g<<a<<endl;
	}
	f.close();
	g.close();
	return 0;
}