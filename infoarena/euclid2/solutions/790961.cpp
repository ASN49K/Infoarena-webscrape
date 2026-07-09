#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long int a,b,c,aux;
int main()
{
	int n;
	f>>n;
	while(n>0)
	{
		n--;
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
	g<<a<<'\n';
}
return 0;

}