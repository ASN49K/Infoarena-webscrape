# include <fstream>
using namespace std;
int main()
{int a,b,r,t,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
for(i=0;i<t;i++)
	{f>>a>>b;
	while(b)
		{r=a%b;
		a=b;
		b=r;}
	g<<a<<endl;}
}
