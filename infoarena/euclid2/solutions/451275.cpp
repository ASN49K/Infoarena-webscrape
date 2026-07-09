#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b)
{
	if(!b)
		return a;
	return (b,a%b);
}
int main ()
{
	int T,a,b;
	in>>T;
	while(T--)
	{
		in>>a>>b;
		out<<cmmdc(a,b)<<'\n';
	}
}