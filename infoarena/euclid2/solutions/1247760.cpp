# include <fstream>
using namespace std;
int main()
{long long int a,b,r,i,n;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=0;i<n;i++)
	{f>>a>>b;
	while(b)
		{r=a%b;
		a=b;
		b=r;}
	g<<a<<'\n';}
}
