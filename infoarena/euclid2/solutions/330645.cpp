#include<fstream.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int n,a,b;
int cmmdc(int x,int y)
{	int m;
	while(x%y!=0)
	{	m=y;
		y=x%y;
		x=m;
	}
	return y;	
}
int main()
{	int i;
	in>>n;
	for(i=1;i<=n;i++)
	{	in>>a>>b;
		out<<cmmdc(a,b)<<'\n';
	}
	in.close();
	out.close();
	return 0;
}	