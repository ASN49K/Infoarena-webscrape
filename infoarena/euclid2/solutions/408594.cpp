#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int t,a,b,i,r;
	ifstream fin("euclid2.in");
	ofstream fout("euclid.out");
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a>>b;
		while(a%b!=0)
		{
		   r=a%b;
		   a=b;
		   b=r;
		}

		fout<<b<<endl;
	}

	return 0;
}
