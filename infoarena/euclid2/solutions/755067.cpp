#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int main()
{
	fin>>n;
	int i, d, max, min;
	for(i=1;i<=n;i++)
	{
		d = 2;
		max = 1;
		fin>>a>>b;
		if(a<b)
			min = a;
		else
			min = b;
		while(a>=d && b>=d && d<=min)
		{
			if(a%d == 0 && b % d ==0)
			{
				a = a/d;
				b = b/d;
				max = max*d;
			}
				d++;
			
		}
	fout<<max<<'\n';	
	}
	return 0;
}