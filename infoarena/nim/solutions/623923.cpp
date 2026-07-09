#include <fstream>
using namespace std;
int n,t,sum,x,i;

int main()
{
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	
	fin>>t;
	while (t--)
	{
		fin>>n;
		int sum=0;
		for (i=0;i<n;++i)
		{
			fin>>x;
			sum^=x;
		}
		
		if (sum) fout<<"DA"<<endl;
			else fout<<"NU"<<endl;
	}
	
	return 0;
}
