using namespace std;
#include<fstream>
int main ()
{
	short int i,n,t,j;
	unsigned int sum,x;
	ifstream f("nim.in");
	ofstream g("nim.out");
	f>>t;
	for(i=1;i<=t;i++)
	{
		f>>n>>x;
		sum=x;
		for(j=2;j<=n;j++)
			f>>x,sum^=x;
		if(sum)
			g<<"DA\n";
		else
			g<<"NU\n";
	}
}