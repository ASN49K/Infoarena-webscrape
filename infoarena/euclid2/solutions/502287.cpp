#include<fstream>
using namespace std;

int euclid(int a, int b)
{
	int rest;
	
	while(b)
	{
		rest = a % b;
		a = b ;
		b = rest;
	}
	return a;
}

int main()

{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	int t,a,b,i;
	
	fin>>t;
	
	for(i = 1 ; i<=t; i++)
	{
		fin>>a>>b;
		fout<<euclid(a,b)<<endl;
	}
	
	return 0;
}