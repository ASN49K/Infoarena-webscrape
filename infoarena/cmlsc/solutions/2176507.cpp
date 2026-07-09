#include <fstream>
#include <iostream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int c[1025][1025], a[1025], b[1025], ans[1025], p;

int main(){
	int m, n, i, j;
	
	in >> m >> n;
	
	for(i = 1; i <= m; i++)
		in >> a[i];
	for(i = 1; i <= n; i++)
		in >> b[i];
		
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)	
			if(a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
				
	out << c[m][n] << '\n';
	
	i = m, j = n;
	
	while(i && j){
		if(a[i] == b[j]){
			ans[++p] = a[i];
			i--, j--;
		}
		else if(c[i - 1][j] > c[i][j - 1])
			i--;
		else
			j--;
	}
	
	for(i = p; i; i--)
		out << ans[i] << " ";
	
	return 0;
}
