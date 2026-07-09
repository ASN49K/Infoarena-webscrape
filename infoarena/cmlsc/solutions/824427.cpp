#include<cstring>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
char s1[100], s2[100], best[100];
int d[100][100], bst, n, m, i, j;
int max(int a, int b){
	if(a>b) return a;
		else return b;
	}
int main(){
	f>>m>>n;
	f>>s1>>s2;
	for(i=1; i<=n; ++i)
		for(j=1; j<=m; ++j)
			if(s1[i]==s2[j])
				d[i][j]=1+d[i-1][j-1];
			else d[i][j]= max(d[i-1][j], d[i][j-1]);
	for(i=n, j=m; i>=1;)
		if(s1[i]==s2[j])
			best[++bst]=s1[i], --i, --j;
		else if(d[i-1][j]<d[i][j-1]) --j;
				else --i;
	for(i=bst; i>=1; --i)
		g<<best[i];
	g<<'\n';
	return 0;
}
