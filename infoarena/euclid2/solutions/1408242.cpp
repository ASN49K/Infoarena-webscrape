#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

void euclid2(unsigned int a, unsigned int b){
	unsigned int rest;
	while (b != 0)
	{
		rest = a%b;
		a = b;
		b = rest;
	}
	if(a==1)
		fout<<0;
	else
		fout << a;
}

int main()
{
	unsigned int a, b;
	int T,i;
	fin>>T;
	
	for(i=0;i<T;i++)
	{
		fin >> a;
		fin >> b;
		euclid2(a,b);
		fout<<endl;
	}
	
	return 0;
}
