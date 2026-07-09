#include<fstream.h>
int a,b,t,i;
long int cmmdc (int x, int y);

int main (void)
{
 ifstream f("euclid2.in");
 ofstream g ("euclid2.out");

 f>>t;
 for (i=0;i<t;i++)
 	{
	f>>a>>b;
        g<<cmmdc (a,b)<<"\n";
     }
 f.close();
 g.close();
 return 0;

}

long int cmmdc (int x, int y)
	{
	if (!y) return x;
        return cmmdc (y,x%y);
	}