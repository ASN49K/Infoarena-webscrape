#include<stdio.h>
#include<fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int T,N,X,a;

int main()
{
	f >> T;
	for(int i=1;i<=T;i++)
	{
		f >> N >> X;
		for(int j=1;j<N;j++)
		{
			f >> a;
			X = X^a;
		}
		
		if(X == 0)
			g << "NU\n";
		else
			g << "DA\n";
	}
	
	return 0;
}