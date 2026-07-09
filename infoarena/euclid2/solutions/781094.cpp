#include <fstream>
#include <algorithm>

using namespace std;

int n, a, b, i;

int main (){
	
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	
	f >> n;
	
	
	for (i = 1; i <= n; i++)
	{
		f >> a >> b;
		
		while (b > 0)
		{
			a = a % b;
			swap (a, b);
		}
		
		g << a << '\n';
	}
	
	return 0;
}
