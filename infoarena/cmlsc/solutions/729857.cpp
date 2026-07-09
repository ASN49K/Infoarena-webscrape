#include <fstream>
using namespace std;

#define maxn 1025
int a[maxn],b[maxn],m,n,c[maxn][maxn],s[maxn],nr;

int main(){
	int i,j;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>a[i];
	for(i=1;i<=n;i++)
		f>>b[i];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else 
				if(c[i-1][j]>c[i][j-1])
					c[i][j]=c[i-1][j];
				else c[i][j]=c[i][j-1];
	while(m&&n){
		if(a[m]==b[n]){
			nr++;
			s[nr]=a[m];
			m--;
			n--;}
		else
			if(c[m-1][n]<c[m][n-1])
				n--;
			else m--;}
	g<<nr<<"\n";
	for(i=nr;i>=1;i--)
		g<<s[i]<<" ";
	f.close();
	g.close();
	return 0;}



	