#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");

int n,i,j,nr,t,rez;

int main() {
	
	fin>>t;
	while(t)
	{
		fin>>n;
		rez=0;
		for(i=1;i<=n;i++)
		{
			fin>>nr;
			rez^=nr;
		}
		if(rez==0)	fout<<"NU\n";
		else	fout<<"DA\n";
		t--;
	}
}
