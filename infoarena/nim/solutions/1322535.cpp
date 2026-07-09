#include<fstream>

using namespace std;

int main()
{
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	int t,n,temp,s=0;
	fin>>t;
	for(int i=0;i<t;i++)
	{
		fin>>n;
		s=0;
		for(int j=0;j<n;j++)
		{
			fin>>temp;
			s=s^temp;
		}
		if(s==0)
		{
			fout<<"NU"<<'\n';
		}
		else
		{
			fout<<"DA"<<'\n';
		}
	}
	return 0;
}
