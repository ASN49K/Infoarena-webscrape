#include <iostream>
#include <fstream>
using namespace std; 
int euclid(int a,int b)
{
	if (a==0 || b==0)	return (a==0?b:a);
	else
	if (a>b)
		return euclid(b,a%b);
	else return euclid(a,b%a);
}

int T,a,b;

int main()
{
	fstream in("euclid2.in");
	in>>T;
	
	for (;T>0;--T)
	{
		in>>a>>b;
		printf("%d\n",euclid(a,b));
	}
}
