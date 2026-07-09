#include <fstream>
using namespace std;
int x,i,n,sum,t;
int main()
{
	ifstream fi("nim.in");
	ofstream fo("nim.out");
	fi>>t;
	for(;t;t--)
	{
		fi>>n;
		for(i=1;i<=n;i++) { fi>>x; sum^=x; }
		if(sum) fo<<"DA\n"; else fo<<"NU\n";
	}
	return 0;
}
