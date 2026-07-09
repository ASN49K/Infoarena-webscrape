#include <iostream>
#include <fstream>
using namespace std;

int m , n , x[1025] , y[1025] , sol[1025][1025] , cont , sir[1025];

int main ()
{
	ifstream f ("cmlsc.in");
	ofstream g ("cmlsc.out");
	
	
	f >> m >> n;
	
	for (int i = 1 ; i <= m ; ++i)
		f >> x[i];
	for (int i = 1 ; i <= n ; ++i)
		f >> y[i];
	
	for (int i = 1 ; i <= m ; ++i)
		for (int j = 1 ; j <= n ; ++j)
			if (x[i] == y[j])
				sol[i][j] = sol[i-1][j-1] + 1;
			else sol[i][j] = max (sol[i][j-1] , sol[i-1][j]);
			
	g << sol[m][n] << "\n";
	
	for (int i = m , j = n ; i && j ; )
		if (x[i] == y[j])
		{
			sir[++cont] = x[i];
			--i;
			--j;
		}
		
		else 
			if (sol[i][j-1] < sol[i-1][j])
				--i;
		else --j;
	
	for (int i = cont ; i >= 1 ; --i)
		g << sir[i] << " ";
	
	return 0;
}
