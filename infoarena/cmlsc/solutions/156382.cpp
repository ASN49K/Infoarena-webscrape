#include<fstream.h>
int v[1025][1025],n,m,a[1025],b[1025];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void citire(){
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>a[i];
	for(int j=1;j<=m;j++)
		fin>>b[j];
}
int max(int x,int y){
	return(x>y)?x:y;
}
void progdin(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				v[i][j]=max(v[i][j-1],v[i-1][j]);
	int sl[1025],s=v[n][m],x=n,y=m;
	for(int i=1;i<=s;i++){
		while(a[x]!=b[y]){
			if(v[x][y]==v[x][y-1])
				y--;
			if(v[x][y]==v[x-1][y])
				x--;
		}
		sl[i]=a[y];
		x--;
		y--;
	}
	for(int i=s;i>=1;i--)
		fout<<sl[i]<<" ";
}
int main(){
	citire();
	progdin();
	fin.close();
	fout.close();
	return 0;
}


