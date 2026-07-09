#include<fstream>
using namespace std;
unsigned long int a,b,c,nr,aux;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>nr;
	while(nr>0)
	{
		nr--;
		f>>a>>b;
		if(a<b)
		{
			aux=a;
			a=b;
			b=aux;
		}
		while(b!=0)
		{
			c=a%b;
			a=b;
			b=c;
		}
		g<<a;
	}
	return 0;
}