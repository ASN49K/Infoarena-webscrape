#include<fstream>
using namespace std;
int main()
{
	ifstream f("cmmdc.in");
	ofstream g("cmmdc.out");
	int T,a,b,r,i;
	f>>T;
	for(i=1;i<=T;i++)
		{
			f>>a>>b;
	        while(b!=0)
			{r=a%b;a=b;b=r;}
			g<<a<<endl;
	}
}
