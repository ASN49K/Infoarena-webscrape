#include<fstream.h>
 ifstream f("cmlsc.in");
  ofstream g("cmlsc.out");
    short x[1025][1025];
	int main(){
		int i,j,n,m,a[1025],b[1025],l,c,v[1025],max,k=0;
		f>>n>>m;
		for(i=1;i<=n;++i) f>>a[i];
		for(j=1;j<=m;++j) f>>b[j];
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j){
				if(a[i]==b[j]){
					x[i][j]=1+x[i-1][j-1];
					l=i;
					c=j;
					//v[++k]=a[i];
				}
				else
					x[i][j]=(x[i-1][j]>x[i][j-1]?x[i-1][j]:x[i][j-1]);
			}
		/*for(i=1;i<=n;++i){
			for(j=1;j<=m;++j) g<<x[i][j]<<' ';
			g<<'\n';
		}*/
		g<<x[n][m]<<'\n';
		max=x[n][m];
		while(max){
			if(a[l]==b[c]){
				v[max]=a[l];
				--l;
				--c;
				--max;
			}
			else{
				if(x[l-1][c]>x[l][c-1]) --l;
				else --c;
			}
		}
		for(i=1;i<=x[n][m];++i) g<<v[i]<<' ';
		g.close();
		return 0;
	}