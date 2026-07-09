#include<fstream>
using namespace std;

int main()

{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	int t,a,b,i,rest;
	
	fin>>t;
	
	for(i = 1 ; i<=t; i++)
	{
		fin>>a>>b;
		
		while(b)
		{
			rest = a % b;
			a = b ;
			b = rest;
		}
		
		fout<<a<<"\n";
	}
	
	fin.close();
	fout.close();
	
	return 0;
}