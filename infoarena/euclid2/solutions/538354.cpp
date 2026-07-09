#include<fstream>
using namespace std;
int main()
{
	int a,b,r,i,T;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for( i=1; i<=T; i++)
	{	
		f>>a; f>>b;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<endl;
	}
	f.close();
	g.close();
	return 0;
}