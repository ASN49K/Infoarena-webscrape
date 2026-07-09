#include<fstream>
#define dim 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[dim],b[dim],D[dim][dim],sol[dim],i,k,j,m,n;
inline int min(int a,int b){
	if(a<b)
		return a;
	return b;
}
int main (){
	f>>n>>m;
	for(i=1;i<=n;i++)
		f>>a[i];
	
	for(i=1;i<=m;i++)
		f>>b[i];
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(a[i]==b[j])
				D[i][j]=1+D[i-1][j-1];
			else{
				D[i][j]=min(D[i-1][j],D[i][j-1]);
			}
		}
	i=n;
	j=m;
	while(i && j){
		if(a[i]==b[j]){
			sol[++k]=a[i];
			--i;
			--j;
		}
		else{
			if(D[i][j-1]>D[i-1][j])
				--j;
			else
				--i;
		}
	}
	g<<k<<"\n";
	for(i=k;i>=1;i--)
		g<<sol[i]<<" ";
	return 0;
}