#include <fstream.h>
int cmmdc(int a, int b)
{	int r=a%b;
	while (r!=0)
	{	a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main ()
{
   ifstream in("euclid2.in");
   ofstream out("euclid2.out");
   int t, i, a, b, c, v;
   in>>t;
   for (i=1; i<=t;i++)
	{ in>>a; in>>b;
	  if (a<b) {a=v; a=b; b=v;}
	  c=cmmdc(a,b);
	  out<<c<<endl;
	}
   in.close ();
   out.close();
   return 0;
}