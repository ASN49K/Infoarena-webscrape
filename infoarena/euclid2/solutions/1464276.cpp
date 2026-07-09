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
	fstream out("euclid2.out",fstream::out);
	in>>T;
	
	for (;T;--T)
	{
		in>>a>>b;
		out<<euclid(a,b)<<"\n";
	}
}
