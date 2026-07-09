#include <fstream>

void cmmdc(int a, int b, int &rez);
std::ifstream f1("euclid2.in");
std::ofstream f2("euclid2.out");

int main()
{
	int n1, n2, divizor, t, i;
	f1>>t;
	for (i=0; i<t; i++)
	{
   	f1>>n1;
	  f1>>n2;
	  cmmdc(n1, n2, divizor);
    f2<<divizor<<"\n";
	}//for i
	f1.close();
	f2.close();
	return 0;
}

void cmmdc(int a, int b, int &rez)
{
	int rest=a%b;
	while (rest>0)
	{
		a=b;
		b=rest;
		rest=a%b;
	}
	rez=b;
}

