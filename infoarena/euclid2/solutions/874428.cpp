#include<iostream>
#include<fstream>

using namespace std;

int gcd(int a,int b)
{
	if(b) return gcd(b,a%b);
	return a;
}

int main()
{
	int x;
	long a,b;
	
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	fin>>x;
	while(x)
	{
		fin>>a>>b;
		fout<<gcd(a,b)<<endl;
		x--;
	}
	fout.close();
	
	return 0;
}