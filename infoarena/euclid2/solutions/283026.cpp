#include<fstream.h>
int main()
{
	int t,a,b,i;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.in");
	fin>>t;
	for(i=0;i<t;i++)
	{
	fin>>a>>b;
	while(a!=b)
	if(a>b) a-=b;
	else b-=a;
	fout<<a<<" ";
	}
	return0;
}