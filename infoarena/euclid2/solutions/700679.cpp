#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b,i;
int main()
{
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>a>>b;
		while(a!=b)
		{
			if(a>b)
				a-=b;
			else
				b-=a;
			if(a==1||b==1)
			{
				a=1;
				break;
			}
		}
		fout<<a<<"\n";
	}
}
