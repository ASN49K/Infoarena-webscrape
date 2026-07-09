#include <fstream>

void cmmdc(int a, int b, int &rez);

int main()
{
	int n1, n2, divizor;
	std::ifstream f1("euclid2.in");
	f1>>n1;
	f1>>n2;
	f1.close();
	cmmdc(n1, n2, divizor);
	std::ofstream f2("euclid2.out");
  f2<<divizor<<"\n";
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

