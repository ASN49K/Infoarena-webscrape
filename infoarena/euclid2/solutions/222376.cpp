#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
	int r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	int a,b,T;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>T;
	for(;T;--T)
	{
		in>>a;
		in>>b;
		out<<cmmdc(a,b)<<"\n";
	}
	return 0;
}
