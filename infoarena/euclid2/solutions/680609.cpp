#include<iostream>
#include<fstream>ad
using namespace std;
int euclid(int a,int b)
{
	int r;
	do
	{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
int main()
{
	ifstream m("euclid2.in");
	ofstream c("euclid2.out");
	int n,x,y,i;
	m>>n;
	for(i=1;i<=n;i++)
	{
		m>>x>>y;
		c<<euclid(x,y);
        c<<"\n";
	}
	m.close();
	c.close();
	return 0;
}
