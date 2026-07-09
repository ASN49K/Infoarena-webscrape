#include <iostream>
#include <fstream>

using namespace std;

ifstream input("euclid2.in");
ofstream output("euclid2.out");

int main()
{
	int T, m, n;
	input >> T;
	
	for(int i = 0; i < T; i++) 
	{
		input >> n >> m;
		
		if(m < n) 
		{
			int x = m;
			m = n;
			n = x;
		}
		
		while(n != 0)
		{
			int r = m%n;
			m = n;
			n = r;
		}
		
		output << m << endl;
	}
	
	return 0;
}
