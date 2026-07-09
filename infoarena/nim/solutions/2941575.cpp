#include <fstream>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <bitset>
#include <map>
#include <cstring>
#include <algorithm>
#define NMAX 1000003
#define MOD 9973

using namespace std;



ifstream fin("nim.in");
ofstream fout("nim.out");

int n;


int main()
{
	
	fin >> n;
	for (int i = 1; i <= n; i++)
	{
		int nrG;
		fin >> nrG;
		int sumaXOR = 0;
		for (int j = 1; j <= nrG; j++)
		{
			int x;
			fin >> x;
			sumaXOR = sumaXOR ^ x;
		}

		if (sumaXOR > 0)
		{
			fout << "DA\n";
		}
		else {
			fout << "NU\n";
		}
	}
	
	return 0;
}