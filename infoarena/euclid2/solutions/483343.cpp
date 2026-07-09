#include <fstream>
using namespace std;
int euclid(int a,int b)
{
	int c;
	do
	{
		if(b>a)
		{
			c=a;
			a=b;
			b=c;
		}
		c=a%b;
		a=c;
	}while(c!=0);
	return b;
}
int main()
{
	int output;
	ifstream IN("euclid2.in");
	ofstream OUT("euclid2.out");
	int a,b,pairs;
	IN>>pairs;
	for(int i=0;i<pairs;++i)
	{
		IN>>a;
		IN>>b;
		output=euclid(a,b);
		OUT<<output<<"\n";
	}
	return 0;
}