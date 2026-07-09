#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int t,i=1,r;
	long long a[100000],b[100000];
	fin>>t;
	while(t--)
	{
		fin>>a[i];
		fin>>b[i];
		i++;
	}
	for(i=1;i<=t;i++)
	{
		if(b[i]>a[i])
		{
			r=a[i];
			a[i]=b[i];
			b[i]=r;
		}
		while(b[i]>0)
		{
			r=a[i]%b[i];
			a[i]=b[i];
			b[i]=r;
		}
		fout<<x<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
