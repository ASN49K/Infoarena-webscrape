#include<fstream>
using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int T,N,A,S;

int main()
{
	f>>T;
	for(;T;--T)
	{
		f>>N;
		S=0;
		for(;N;--N)
			f>>A, S^=A;
		if(S) g<<"DA\n";
		else g<<"NU\n";
	}
	return 0;
}
