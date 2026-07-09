#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	int contor, nr1, nr2,r=1;
	f >> contor;
	while (contor > 0)
	{
		f >> nr1 >> nr2;
		while (nr2){
			r = nr1%nr2;
			nr1 = nr2;
			nr2 = r;
		}
		g << nr1 <<"\n";
		--contor;
	}
	return 0;
}
