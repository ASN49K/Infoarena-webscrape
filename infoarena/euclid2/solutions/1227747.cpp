#include<iostream>
#include<fstream>
using namespace std;

	fstream fin("euclid2.in", ios::in),fout("euclid2.out",ios::out);

int cmmdc (int a, int b)
{
	int d;
	while (b!=0)
	{
		d=b;
		b=a%b;
		a=d;
	}
	return d;
}


int main()
{
	int T,i,d,x,y;
	fin>>T;

	for(i=1;i<=T;i++)
	{
		fin>>x>>y;
		d=cmmdc(x,y);
		fout<<d;
	}




fin.close();
fout.close();
return 0;
}
