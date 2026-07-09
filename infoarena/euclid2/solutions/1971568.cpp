#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int numar, primulNumar, aldoileaNumar;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> numar;
	for (int i = 0; i < numar; i++)
	{
		f >> primulNumar >> aldoileaNumar;
		while (aldoileaNumar != 0)
		{
			int rest = primulNumar%aldoileaNumar;
			primulNumar = aldoileaNumar;
			aldoileaNumar = rest;
		}
		g << primulNumar<<endl;
	}
	f.close();
	g.close();
	return 0;
}