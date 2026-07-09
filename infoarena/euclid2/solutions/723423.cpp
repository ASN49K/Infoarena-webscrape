#include<iostream>
using namespace std;
#include <fstream>

int cmmdc(long a,long b)
{
	int r;
	r = a % b;
	while (r != 0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	ifstream inFile;
	inFile.open("euclid2.in");
	ofstream outFile;
	outFile.open("euclid2.out");
	short n;
	long a,b;
	inFile>>n;
	for (int i=0;i<n;++i)
	{
		inFile>>a>>b;
		outFile<<cmmdc(a,b)<<endl;
	}
	outFile.close();
	inFile.close();
	return 0;
}