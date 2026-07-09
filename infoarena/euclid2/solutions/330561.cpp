#include<fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int a,b;
int cmmdc(int a,int b)
{
	int r;
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
	int t,a,b;
	in>>t;
	for(int i=1;i<=t;i++)
	{
		in>>a>>b;
		out<<cmmdc(a,b)<<endl;
	}
	return 0;
}
