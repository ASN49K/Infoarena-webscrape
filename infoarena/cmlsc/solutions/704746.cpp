#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1024], b[1024], n, m, d[1024][1024];
void Read()
{
	fin >> n >> m;
	for(int i = 1; i <= n; i++)
		fin >> a[i];
	for(int j = 1; j <= m; j++)
		fin >> a[j];
}
void Cmlsc()
{
	for(int i = 1; i <= m; i++)
		d[i][0] = i;
	for(int j = 1; j <= n; j++)
		d[0][j] = j;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i] == b[j])
				d[i][j] = 1 + d[i - 1][j - 1];
			else
				d[i][j] = max(d[i][j - 1], d[i - 1][j]);
				fout << d[n][m];
}
int main()
{
	Read();
	Cmlsc();
	fin.close();
	fout.close();
	return 0;
}
