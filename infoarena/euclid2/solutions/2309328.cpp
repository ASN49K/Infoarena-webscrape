#include <fstream>
using namespace std;

int q[100];
void func(int a)
{
	q[a%100] = a;
}

int T, A, B;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
	in >> T;
	for(; T; --T)
	{
		for(int i = 0; i < 1999999999; i++)
			func(i);
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