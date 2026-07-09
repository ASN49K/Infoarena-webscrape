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
   int n, i, a, b, c;
   in>>n;
   for (i=1; i<=n;i++)
	{ in>>a; in>>b;
	  c=cmmdc(a,b);
	  out<<c<<endl;
	}
   out.close();
   return 0;
}