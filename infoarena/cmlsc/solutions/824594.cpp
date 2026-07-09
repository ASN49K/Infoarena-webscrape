#include<cstring>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
char s1[1050], s2[1050], best[1050];
int d[1050][1050], bst, n, m, i, j;
int max(int a, int b){
	if(a>b) return a;
		else return b;
	}
int main(){
	f>>n>>m;
	for(i=1; i<=n; ++i) f>>s1[i];
	for(i=1; i<=m; ++i) f>>s2[i];
	for(i=1; i<=n; ++i)
		for(j=1; j<=m; ++j)
			if(s1[i]==s2[j])
				d[i][j]=1+d[i-1][j-1];
			else d[i][j]= max(d[i-1][j], d[i][j-1]);
	for(i=n, j=m; i;)
		if(s1[i]==s2[j])
			best[++bst]=s1[i], --i, --j;
		else if(d[i-1][j]<d[i][j-1]) --j;
				else --i;
	g<<bst<<'\n';
	for(i=bst; i>=1; --i)
		g<<best[i]<<' ';
	g<<'\n';
	return 0;
}
