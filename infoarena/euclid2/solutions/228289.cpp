#include<fstream>
#include<iostream>     
using  namespace std;
int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()    
{
	ifstream fin("euclid2.in");    
	ofstream fout("euclid2.out");
	int nrt;
	fin>>nrt;
	for(int test = 0; test<nrt; test++)
	{
		int x,y;	
		fin>>x>>y;
		int gc=gcd(x,y);
		fout<<gc<<endl;
	}
	fout.close();
	return 0;
}
