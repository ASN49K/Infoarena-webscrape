#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

//returns the greatest common divisior
int gcd(int a, int b)
{
	int a1 = max(a, b);
	int b1 = min(a, b);
	int r = b1;

	while (r != 0)
	{
		r = a1%b1;
		a1 = b1;
		b1 = r;
	}

	return a1;
}

//int e_000_euclid()
int main()
{
	char* in_file = "euclid2.in";
	char* out_file = "euclid2.out";

	int T;
	
	ifstream ifs(in_file);
	ofstream ofs(out_file);
	ifs>>T;
	for (int i = 0; i < T; i++)
	{
		int a, b;
		ifs>>a>>b;
		ofs<<gcd(a, b)<<endl;
	}
	ifs.close();			
	ofs.close();

	return 0;
}