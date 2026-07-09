#include<fstream.h>
int a,b;
int cmmdc (int x, int y);

int main (void)
{
 ifstream f("euclid2.in");
 ofstream g ("euclid2.out");

 f>>a>>b;

 g<<cmmdc (a,b);

 f.close();
 g.close();
 return 0;

}

int cmmdc (int x, int y)
	{
	if (!y) return x;
        return cmmdc (y,x%y);
	}