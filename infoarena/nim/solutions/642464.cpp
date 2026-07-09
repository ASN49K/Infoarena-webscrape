#include <fstream>
using namespace std;

int T, N, x, win;
ifstream f("nim.in");
ofstream g("nim.out");

int main(void)
{
	f >> T;
	while(T--)
	{
		f >> N;
		win = 0;
		for(int i = 1; i <= N; ++i)
		{
			f >> x;
			win = win ^ x;
		}
		if(win)
			g << "DA\n";
		else
			g << "NU\n";
	}
	
	f.close();
	g.close();
	
	return 0;
}