#include <fstream>

using namespace std;

int euclid(int a ,int b)
{
	if(!b) return a;
	return euclid(b, a % b);
}

int main(void)
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	unsigned long long a, b, n;
	fin >> n;
	for(; n ;--n)
	{
		fin >> a >> b;
		fout << euclid(a, b) << endl;
	}
return  0;
}
