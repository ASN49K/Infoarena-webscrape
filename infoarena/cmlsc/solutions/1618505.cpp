#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define max(a,b) (a>b ? a : b)

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int lcs[1025][1025];

int main() {
	int m, n,i,j;
	fin>>m, fin>>n;
	vector<int> a(m), b(n);
	for (i = 0; i<m; i++)
		fin>>a[i];
	for (i = 0; i<n;i++)
		fin>>b[i];
	for (i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if (a[i-1] == b[j-1])
				lcs[i][j] = 1 + max (lcs[i-1][j],lcs[i][j-1]);
			else
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
		}
	/*for (i = 0; i<=m; i++)
	{
		for (j = 0; j<=n; j++)
			cout<<lcs[i][j]<<" ";
		cout<<endl;
	}*/
	int length = -1;
	int sir[m];
	i = m, j = n;
	while (i>0 && j>0 && lcs[i][j])
		if (a[i-1]==b[j-1])
			sir[++length]=a[i-1],--i,--j;
		else if (lcs[i][j-1] >lcs[i-1][j])
			--j;
		else 
			--i;
	fout<<(length+1)<<endl;
	for (i = length;i>=0;--i)
		fout<<sir[i]<<" ";
	fout.close();
	return 0;
}