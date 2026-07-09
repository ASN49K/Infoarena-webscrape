#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, cmmdc,i,r,x,y,rez;
int euclid(int a, int b)
{
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	fin >> n;
	for (i = 0; i < n; i++)
	{
		fin >> x >> y;
		rez = euclid(x, y);
		fout << rez << "\n";
		
	}

fin.close();
fout.close();	


	return 0;
}