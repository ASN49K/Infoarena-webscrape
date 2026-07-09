#include<fstream>
using namespace std;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int T,a,b,r,i;
	f>>T;
	for(T;--T)
		{
			f>>a>>b;
	        while(b!=0)
			{r=a%b;a=b;b=r;}
			g<<a<<'\n';
	}
}
