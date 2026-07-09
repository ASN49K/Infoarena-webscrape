#include<fstream>
using namespace std;

int main()
{
	long long a,b,r;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>a>>b;
	while(b!=0)
	{
	 r=a%b;
	 a=b;
	 b=r;
	}
	if(a==1)
		a=0;
	out<<a;
	return 0;
}
