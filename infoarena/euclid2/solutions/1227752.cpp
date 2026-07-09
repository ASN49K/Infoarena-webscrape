#include<iostream>
#include<fstream>
using namespace std;

	fstream fin("euclid2.in", ios::in),fout("euclid2.out",ios::out);

int cmmdc (int a, int b)
{
    int d=1;
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
	int T,i,x,y,diviz;
	fin>>T;

	for(i=1;i<=T;i++)
	{
		fin>>x>>y;
        diviz=cmmdc(x,y);
		fout<<diviz<<'\n';
	}




fin.close();
fout.close();
return 0;
}
