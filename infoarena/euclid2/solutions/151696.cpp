#include<fstream.h>

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int a,b,div,min,i;
	fin>>a>>b;
	if(a<b) min=a;
	else min=b;
	if(a-b<5000) {
	while(a!=b)
	{
		if(a>b) a=a-b;
		else b=b-a;
	}  div=a;}
	else for(i=2;i<min;i++)
	if(!(a%i&&b%i)) div=i;
	fout<<div;
	return 0;
}