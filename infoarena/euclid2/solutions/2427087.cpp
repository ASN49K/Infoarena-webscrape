#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int a, b;
	int t;
	fin >> t;
	for (int i = 1; i <= t; i++)
		fout << __gcd(a, b)<<endl;
}
