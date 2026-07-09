#include<fstream>
using namespace std;
ifstream fcin("euclid2.in");
ofstream fcout("euclid2.out")
long long cmmdc(long long a,long long b)
{
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}
void rezolva()
{
	long long a,b;
	fcin>>a>>b;
	fcout<<cmmdc(a,b)<<"\n";
}
int main()
{
	long long t;
	for(fcin>>t;t;t--)
		rezolva();
	return 0;
}
	