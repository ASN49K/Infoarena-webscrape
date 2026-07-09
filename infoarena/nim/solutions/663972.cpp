#include <fstream>

using namespace std;

const char InFile[]="nim.in";
const char OutFile[]="nim.out";

ifstream fin(InFile);
ofstream fout(OutFile);

int T,N,S,x;

int main()
{
	fin>>T;
	for(register int i=0;i<T;++i)
	{
		fin>>N;
		S=0;
		for(register int j=0;j<N;++j)
		{
			fin>>x;
			S^=x;
		}
		if(!S)
		{
			fout<<"NU\n";
		}
		else
		{
			fout<<"DA\n";
		}
	}
	fin.close();
	fout.close();
	return 0;
}
