#include<fstream.h>
int v[102][102],n,m,a[1025],b[1025];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void citire(){
	fin>>m>>n;
	for(int i=1;i<=n;i++)
		fin>>a[i];
	for(int j=1;j<=m;j++)
		fin>>b[j];
}
int maxim(int x,int y){
	return(x>y)?x:y;
}
void afis(){
for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++){
			if (a[j]==b[i])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=maxim(v[i][j-1],v[i-1][j]);
		}
	int x=m, y=n,s,sl[1025];
	s=v[m][n];
	fout<<v[m][n]<<'\n';
	for (i=1; i<=s; i++){
		while(a[y]!=b[x]){
			if (v[x][y]==v[x][y-1])
				y--;
			if (v[x][y]==v[x-1][y])
				x--;
		}
		sl[i]=a[x];
		x--;
		y--;
	}
	for (i=s; i>=1; i--){
		fout<<sl[i]<<" ";
	}
}
int main(){
	citire();
	afis();
	fin.close();
	fout.close();
	return 0;
}
