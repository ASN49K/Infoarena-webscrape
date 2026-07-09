#include<fstream.h>

ifstream fin ("euclid2.in");
ofstream fout("euclid2.out");


long n;
unsigned long long a, b;

int cmmdc(int a, int b);

int main()
{
	fin>>n;
	for(int i=0; i<n; i++)
	{
	fin>>a>>b;
	fout<<cmmdc(a, b)<<"\n";
	}

return 0;

}

int cmmdc(int a, int b)
{
if(b==0) return a;
else
return cmmdc(b, a%b);
}
