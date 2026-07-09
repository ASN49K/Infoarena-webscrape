#include<fstream>
using namespace std;
int main()
{int i,j,n,x,x2,nr;
	ifstream f("nim.in");ofstream g("nim.out");
	f>>n;
	for(i=1;i<=n;i++)
	{
		f>>nr;
		f>>x;
		for(j=2;j<=nr;j++)
			{ f>>x2; x=x^x2;}
		if(x)g<<"DA\n";
		else g<<"NU\n";
	}
return 0;}
