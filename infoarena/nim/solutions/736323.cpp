#include<fstream>
using namespace std;
int main()
{
	ifstream fcin("nim.in");
	ofstream fcout("nim.out");
	int i,n,s,t,j,x;
	fcin>>t;
	for(i=1;i<=t;i++)
	{
		fcin>>n;
		s=0;
		for(j=1;j<=n;j++)
		{
			fcin>>x;
			s=s^x;
		}
		if(s)
			fcout<<"DA\n";
		else
			fcout<<"NU\n";
	}
	return 0;
}
