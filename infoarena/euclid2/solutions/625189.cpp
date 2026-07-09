#include<fstream>
using namespace std;
int main()
{
	int t,i,r,a,b;
	ifstream f("euclid2.in");
    ofstream g("euclid2.out");
	f>>t;
	for(i=0;i<t;i++)
	{   
		f>>a>>b;
		r=a%b;
		while(r!=0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<a;
		
	}
	f.close();
	g.close();
	return 0;
}