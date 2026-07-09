#include <fstream>
#include <iostream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T, A, B;



int main()
{
	int i;

	for (in>>T; T; --T)
	{
		in>>A>>B;
		for (i = (A < B) ? A : B; i; --i)
			if (A % i == 0 && B % i == 0)
			{
				out<<i<<'\n';
				break;
			}
	}

	return 0;
}
