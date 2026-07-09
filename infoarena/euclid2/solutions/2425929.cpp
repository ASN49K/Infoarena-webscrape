
#include <fstream>

using namespace std;

int euclid(int a ,int b)
{
	if(!b) return a;
	return euclid(b, a % b);
}

int main()
{
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a, b, n;
fin >> n;
for(int i = 0; i<n; i++)
{
	fin >> a >> b;
	fout << euclid(a, b) <<'\n';
}
}
