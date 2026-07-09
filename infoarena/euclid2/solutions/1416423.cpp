#include<fstream>
using namespace std;


int euclid(int x,int y)
{
	int r=0;
	while(y)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}

int main()
{
	int t;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	in>>t;
	int a,b;
	for(int i=1;i<=t;i++)
	{
		in>>a>>b;
		out<<euclid(a,b)<<'\n';
	}
	
	return 0;
}