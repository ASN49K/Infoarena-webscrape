#include<fstream>

using namespace std;

int main()
{
	int i,a,b,T;
	
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	
	f>>T;
	for(i=0;i<T;i++)
	{
		f>>a>>b;
		if(a==0)
			g<<b;
		else if(b==0)
			g<<a;
		else
		{
			while(a!=b)
			{
				if(a>b)
					a=a-b;
				if(b>a)
					b=b-a;
			}
			g<<a<<endl;
		}
	}
	f.close();
	g.close();
	return 0;
}