#include<fstream>
using namespace std;
int d[1024][1024],w[1024],x[1024],y[1024];
int main(){
	int m,n,i,j,nr=0,a;
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	f>>m>>n;
	for(i=1;i<=m;i++)
		f>>x[i];
	for(i=1;i<=n;i++)
		f>>y[i];
	f.close();
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(x[i]==y[j]){
				d[i][j]=d[i-1][j-1]+1;
			}
			else{
				if(d[i-1][j]>d[i][j-1]) d[i][j]=d[i-1][j];
				else d[i][j]=d[i][j-1];
			}
		}
	}
	g<<d[m][n]<<'\n';
	nr=d[m][n];
	i=m;
	j=n;
	a=nr;
	while(nr>0){
		if(x[i]==y[j]){
			w[nr]=x[i];
			i--;
			j--;
			nr--;
		}
		else{
			if(d[i][j]==d[i-1][j]) i--;
			else j--;
		}
	}
	for(i=1;i<=a;i++)
		g<<w[i]<<" ";
	g<<'\n';
	g<<'\n';
	g.close();
	return 0;}
