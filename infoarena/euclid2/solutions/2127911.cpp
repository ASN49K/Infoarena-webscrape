#include <iostream>
#include <fstream>

using namespace std;

ifstream input("euclid2.in");
ofstream output("euclid2.out");

int main()
{
	int T, m, n, r;
	input >> T;
	
	for(int i = 0; i < T; i++) 
	{
		input >> n >> m;
		
		if(m < n) 
		{
			while(m != 0)
			{
				r = n%m;
				n = m;
				m = r;
			}
			output << n << endl;
		}
		else {
			while(n != 0)
			{
				r = m%n;
				m = n;
				n = r;
			}
			output << m << endl;
		}
		
		
	}
	
	return 0;
}
