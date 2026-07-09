#include <iostream.h>
#include <fstream.h>
fstream f("cmmdc.in",ios::in);
fstream g("cmmdc.out",ios::out);
int main ()
{
	int a,b,r,t;
	f>>t;
	f>>a; f>>b;
	while (t>0) {
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
			t--;
		      }
f.close ();
g.close ();
return 0;
}
