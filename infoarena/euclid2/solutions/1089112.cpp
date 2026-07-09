using namespace std;
#include<fstream>
#include<iostream>

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n;

int main()
{

	int a, b;
	f>>n;

	for(int i=0;i<n;i++)
	{
		f>>a>>b;
		while(a!=0 && b!=0)
			if(a>b)
				a=a%b;
			else
				b=b%a;
		
		if(a>0)
			g<<a<<endl;
		else
			g<<b<<endl;
	}


	return 0;
}