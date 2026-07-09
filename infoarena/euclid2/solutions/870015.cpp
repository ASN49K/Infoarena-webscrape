#include<fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
	int r=a%b;
	while (r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int t,i,x,y;

int main()
{
	in>>t;
	for (i=1;i<=t;i++)
	{
		in>>x>>y;
		out<<euclid(x,y)<<'\n';
	}
}