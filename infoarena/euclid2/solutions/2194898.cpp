
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream be("euclid2.in");
	ofstream ki("euclid2.out");
	int n;
	int a, b;
	be >> n;

	for (int i = 0; i < n; i++)
	{
		be >> a >> b;
	
	
		
		while(true)
		{
			if (a % b == 0)
			{
				ki << b << endl;
				break;
			}
			if (b % a == 0)
			{
				ki << a << endl;
				break;
			}

			if (a > b)
				a %= b;
			else
				b %= a;

		} 
			
		
			
	}

	return 0;
}
