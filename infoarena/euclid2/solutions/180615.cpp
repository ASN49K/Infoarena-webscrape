#include<fstream.h>

long int T,a,b;

int main()
{	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>T;
	for(int i=1;i<=T;i++)
	{	f>>a>>b;
		while(a%b)
		{      int r=a%b;
			   a=b;
			   b=r;
		}

		g<<b<<"\n";
	}

	f.close();
	g.close();
	return 0;
}