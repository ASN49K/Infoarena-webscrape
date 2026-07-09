#include<fstream>
#define dim 1025

using namespace std;


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v[dim],a[dim],b[dim];
int i,j,k,n,m;
int d[dim][dim];
inline int maxim(int a,int b){
	if(a>b)
		return a;
	return b;
}
int main (){
	
	f>>n>>m;
	
	for(i=1;i<=n;++i)
		f>>a[i];
	for(i=1;i<=m;++i)
		f>>b[i];
	
	for(i=1;i<=n;++i){
		
		for(j=1;j<=m;++j){
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=maxim(d[i-1][j],d[i][j]);
		}
	}
	i=n;
	j=m;
	k=0;
	
	while(i && j){
		
		if(a[i]==b[j]){
			v[++k]=a[i];
			--j;
			--i;
		}
		else {
			if(d[i-1][j]>d[i][j-1])
				--i;
			else
				--j;
		}
	}
	g<<k<<"\n";
	for(i=k;i;--i)
		g<<v[i]<<" ";
}