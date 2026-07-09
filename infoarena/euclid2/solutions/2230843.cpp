#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");
#define cout g

int main()
{
	int a = 21;
	int b = 14;

	while (a != b && a != 0 && b != 0)
	{
		if (a > b) 
		{
			a = a % b;
		} 
		else 
		if (b > a) 
		{
			b = b % a;
		}
	}
	cout << max(a, b) << endl;

	return 0;
}

