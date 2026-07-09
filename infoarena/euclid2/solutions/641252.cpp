#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int u(int a,int b)
{int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
return a;
}
int main()
{	
	const int max=100000;
	int n[max][3],d,i,j;
		f>>d;
		for(i=1;i<=d;i++)
			for(j=1;j<=2;j++)
				f>>n[i][j];
		for(i=1;i<=d;i++)
			g<<u(n[i][1],n[i][2])<<"\n";
	return 0;
}