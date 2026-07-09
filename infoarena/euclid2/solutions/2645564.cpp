
// link: https://infoarena.ro/problema/euclid2 //

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string problem = "euclid2";
ifstream fin(problem + ".in");
ofstream fout(problem + ".out");
#define ll long long
int t;
ll a, b;

ll euclid(ll a, ll b)
{

	while (b)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	fin >> t;
	while (t--)
	{
		fin >> a >> b;
		fout << euclid(a, b) << "\n";
	}
}  

