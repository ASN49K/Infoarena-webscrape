#include<fstream>
using namespace std;
int main()
{
	int i,n,a,b;
	ifstream f("euclid2.in");
    ofstream g("euclid2.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>a>>b;
	    while(a!=b)
		{
			if(a>b)
				a-=b;
			else
				b-=a;
		}
		g<<a;
		g<<endl;
	}
	return 0;
}