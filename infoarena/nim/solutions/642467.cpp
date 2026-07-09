//nim_compact.cpp
#include <fstream>
using namespace std;

int N, T, win, x;
ifstream f("nim.in");
ofstream g("nim.out");

int main(void)
{
	f >> T;
	while(T--)
	{
		win = 0;
		for((f >> N); N; --N)
			f >> x, win = win ^ x;
		g << ((win > 0) ? "DA\n" : "NU\n");
	}
	
	f.close();
	g.close();
	
	return 0;
}