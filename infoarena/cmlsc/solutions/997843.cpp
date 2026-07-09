#include<fstream>
#define dim 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
inline int maxim (  int a,int b ) {
	if(a>b) 
		return a;
	return b;
}
int i,j,n,m,k;
int a[dim],b[dim],D[dim][dim],s[dim];
int main () {
	
	f>>n>>m;
	
	
	for(i=1;i<=n;++i)
		f>>a[i];
	for(i=1;i<=m;++i)
		f>>b[i];
	
	
	for(i=1;i<=n;i++) {
		
		for(j=1;j<=m;++j){
			
			if( a[i]==b[j] ) {
				
				D[i][j]=D[i-1][j-1]+1;
			}
			else {
				
				D[i][j]=maxim(D[i-1][j],D[i][j-1]);
				
			}
		}
		
	}
	
	i=n;
	j=m;
	k=0;
	while( i && j ) {
		
		if(a[i]==b[j]) {
			s[++k]=a[i];
			--i;
			--j;
		}
		else {
			
			if(D[i-1][j]>D[i][j-1]){
				--i;
			}
			else{
				--j;
			}
			
		}
	}
	g<<k<<"\n";
	for(i=k;i;--i) {
		g<<s[i]<<" ";
	}
	return 0;
}