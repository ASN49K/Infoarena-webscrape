#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;

int main()
{
	fin>>n;
	int i, d = 2 ,x, max = 0;;
	for(i=1;i<=n;i++)
	{
		d = 2;
		max = 1;
		fin>>a>>b;
		while(a>=d && b>=d)
		{
			if(a%d == 0 && b % d ==0)
			{
				a = a/d;
				b = b/d;
				if(d>max)
					max = max*d;
			}
			else
				d++;
			
		}
	fout<<max<<'\n';	
	}
	return 0;
}