#include <fstream>
	
#include <algorithm>
	
	
	
#define MAX 1030
	
using namespace std;
	
	
	
ifstream fin ("cmlsc.in");	
	
ofstream fout("cmlsc.out");
	
	
	
 
	
	
	
int a[MAX], b[MAX];
	
int cmlsc[MAX][MAX];
	
int sir[MAX];
	
	
	
int main() {
	
	int n, m;
	
	fin >> n >> m;
	
	for (int i = 1;i <= n;i ++)
	
		fin >> a[i];
	
	
	
	for (int i = 1;i <= m;i ++)
	
		fin >> b[i];
	
	
	
	for (int i = 1;i <= n;i ++)
	
		for (int j = 1;j <= m;j ++)
	
			if (a[i] == b[j])
	
				cmlsc[i][j] = cmlsc[i - 1][j - 1] + 1;
	
			else
	
				cmlsc[i][j] = max(cmlsc[i - 1][j], cmlsc[i][j - 1]);
	
	
	
	int index = 0;
	
	for (int i = n, j = m;i >= 1 and j >= 1;) {
	
		if (a[i] == b[j])
	
			sir[++ index] = a[i], i --, j --;
	
		else if (cmlsc[i - 1][j] < cmlsc[i][j - 1])
	
			j --;
	
		else
	
			i --;
	
	}
	
	
	
	fout << index << '\n';
	
	for (int i = index;i >= 1;i --)
	
		fout << sir[i] << ' ';
	
	return 0;
	
}