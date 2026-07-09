#include<iostream>
#include<fstream>

using namespace std;

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
		while(a!=b)
		{
			if(a>b) a-=b;
			else b-=a;
		}
		fout<<a<<endl;
		x--;
	}
	
	return 0;
}