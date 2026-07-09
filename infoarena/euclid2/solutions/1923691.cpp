#include <fstream>

using namespace std;

ifstream in("cmmdc.in");
ofstream out("cmmdc.out");

int fdivizor(int numar1, int numar2)
{
	while(numar1!=numar2)
	{
		if(numar1>numar2)
			numar1=numar1-numar2;
		else
			numar2=numar2-numar1;
	}
		return numar1;
}

int euclid(int num1, int num2)
{
	int rest;
	while (num2)
	{
		rest = num1%num2;
		num1=num2;
		num2=rest;
	}
	return num1;
}

int main()
{
	int a, b;
	in>>a;
	in>>b;
	out<<euclid(a,b);
	return 0;
}
