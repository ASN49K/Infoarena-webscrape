#include<fstream.h>
long a,b,d;
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>a>>b;
	do
	{
		d=a%b;
		a=b;
		b=d;
	}
	while(d);
	fout<<a;
	return 0;
}