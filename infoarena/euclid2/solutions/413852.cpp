#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int t,i,j,r,A[10000][2],a,b;
	
	f>>t;
	for(i=0;i<t;i++)
		for(j=0;j<2;j++)
			f>>A[i][j];
	
	for(i=0;i<t;i++)
	{
		a=A[i][0];
		b=A[i][1];
		r=a%b;
		while(r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		g<<b<<endl;
	}
	return 0;
}