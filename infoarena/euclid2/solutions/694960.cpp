#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
	int a,b,r,t,i;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
		in>>t;
	

	for (i=1;i<=t;i++)
	{
	in>>a>>b;
		r=a%b;
	while (r!=0)
	{
		a=b;
		b=r;
		r=a%b;
		
	}
	out<<b<<'\n';
	}
	in.close();
	out.close();
	
	return 0;
}
