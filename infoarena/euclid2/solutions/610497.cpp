#include<iostream>
#include<fstream>
using namespace std;

int cmmdc(int a, int b)
{
	if(a%b==0) return b;
	else return cmmdc(b,a%b);
}

int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int x,y,n,i;
	f>>n;
	for(i=1; i<=n; i++)
	{
		f>>x>>y;
		g<<cmmdc(x,y)<<endl;
	}
	f.close();
	g.close();
}