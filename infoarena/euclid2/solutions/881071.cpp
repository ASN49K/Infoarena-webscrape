using namespace std;
#include<fstream>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int a, b, n, t, i;
	fin>>n;
	for(i=1;i<=n;i++)
		{fin>>a>>b;
		while(b)
		{	t=b;
			b=a%b;
			a=t;
		}
		fout<<a<<"\n";
		}
}
