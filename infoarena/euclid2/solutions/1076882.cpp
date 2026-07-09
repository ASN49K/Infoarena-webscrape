#include<fstream>
using namespace std;

ifstream r("euclid2.in");
ofstream w("euclid2.out");

unsigned T,a,b;

unsigned cmmdc(unsigned a,unsigned b)
{
	if(!b) return a;
	else cmmdc(b,a%b);
}

int main()
{
	r>>T;
	while(T)
	{
		r>>a>>b;
		w<<cmmdc(a,b)<<"\n";
		T--;
	}

	r.close(); w.close();
	return 0;
}