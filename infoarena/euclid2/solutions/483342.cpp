#include <fstream>
using namespace std;
int main()
{
	ifstream IN("euclid2.in");
	ofstream OUT("euclid2.out");
	int a,b,pairs;
	IN>>pairs;
	for(int i=0;i<pairs;++i)
	{
		IN>>a;
		IN>>b;
		while(a!=b)
		{
			if(a>b) a-=b;
			else if(b>a) b-=a;
		}
		OUT<<a<<"\n";
	}
	return 0;
}