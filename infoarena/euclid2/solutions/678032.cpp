#include<fstream>
using namespace std;
int main()
{
	int n,a,b,r,aux;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	while(f>>a>>b)
	{
		if(a<b)
		{
			aux=a;
			a=b;
			b=aux;
		}
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