#include<iostream.h>
#include<fstream.h>
int main()
{
int t,aux,a,b,i;
fstream f("euclid2.in",ios::in),g("euclid2.out",ios::out);
f>>t;
while(t>0)
	{
	f>>a>>b;
	while(b!=0)
		{
		aux=b;
		b=a%b;
		a=aux;
		}
	g<<a<<endl;
	t--;
	}
f.close();g.close();
}