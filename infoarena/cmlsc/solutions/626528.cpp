#include<fstream>
#include<vector>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector<int> v;
int mat[1025][1025];
int a[1025];
int b[1025];

int main()
{
	int n, m;
	fin >> n >> m;
	for ( int i = 1; i <= n; i++ )
		fin >> a[i];
	for ( int i = 1; i <= m; i++ )
		fin >> b[i];
	for ( int i = 1; i <= n; i++ )
		for ( int j = 1; j <= m; j++ )
			if ( a[i] == b[j] )
				mat[i][j] = 1 + mat[i-1][j-1];
			else
				if ( mat[i-1][j] > mat[i][j-1] )
					mat[i][j] = mat[i-1][j];
				else mat[i][j] = mat[i][j-1];
	for ( int i = n, j = m; i; )
		if ( a[i] == b[j] )
		{
			v.push_back( a[i] );
			i--;
			j--;
		}
		else 
			if ( mat[i-1][j] < mat[i][j-1] )
				j--;
			else
				i--;
	/*for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= m; j++ )
			fout << mat[i][j] << ' ';
		fout << '\n';
	}*/
	fout << v.size();
	fout << '\n';
	for ( ; v.size() ; v.pop_back() )
	{
		fout << v.back() << ' ';
	}
	fin.close();
	fout.close();
	return 0;
}
