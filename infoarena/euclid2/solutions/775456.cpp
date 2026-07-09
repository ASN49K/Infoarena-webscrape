#include<fstream>

using namespace std;

int main()
{
	int i;
	long T;
	long long a,b;
	
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	
	f>>T;
	for(i=0;i<T;i++)
	{
		f>>a>>b;
		while(a!=b)
		{
			if(a>b)
				a=a-b;
			if(b>a)
				b=b-a;
		}
		g<<a<<endl;
	}
	f.close();
	g.close();
	return 0;
}