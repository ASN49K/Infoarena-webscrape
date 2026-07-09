
#include <fstream>

using namespace std;

int euclid(int a ,int b)
{
	while(a!=b)
		if(a > b) a = a -b;
		else b = b - a;
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
