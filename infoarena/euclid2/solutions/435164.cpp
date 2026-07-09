#include<fstream>

using namespace std;

const char iname[]="euclid2.in";
const char oname[]="euclid2.out";

ifstream f(iname);
ofstream g(oname);

int a,b,t,i;

int cmmdc(int a,int b)
{
	if(b==0)
		return a;	
	return cmmdc(b,a%b);
}

void far()
{
	f>>a>>b;
	g<<cmmdc(a,b)<<"\n";
}

int main()
{
	f>>t;
	for(i=1;i<=t;++i)
		far();
	f.close();
	g.close();

	return 0;
}