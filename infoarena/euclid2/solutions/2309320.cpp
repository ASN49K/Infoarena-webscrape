#include <fstream>
using namespace std;

int T, A, B;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
	in >> T;
	for(; T; --T)
	{
		for(int i = 0; i < 409054004; i++){}
		in >> A >> B;
		while(A != B)
		{
			if(A > B)
				A -= B;
			else
				B -= A;
		}
		out << A << endl;
	}
	return 0;
}