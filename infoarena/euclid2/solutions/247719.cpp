#include <iostream.h>
#include <fstream.h>
fstream f("cmmdc.in",ios::in);
fstream g("cmmdc.out",ios::out);
int main ()
{
	int a,b,r;
	f>>a; f>>b;
	do {
		r=a%b;
		a=b;
		b=r;
	   }
	while (r!=0);
	if (a==1) g<<"0";
		else {
			g<<a;
		     }
f.close ();
g.close ();
return 0;
}
