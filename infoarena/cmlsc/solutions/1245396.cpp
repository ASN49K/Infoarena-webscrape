#include<iostream>
#include<fstream>
#define max(a,b) ((a>b)?a:b)
#define  NMAX 1024
using namespace std;


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v1[NMAX], v2[NMAX], aux[NMAX][NMAX], result[NMAX], k=0;
int  n , m ;	

int main(){
	int i,j;
	f>>n>>m;
 	
	for(i=1; i<=n; i++) 	f>>v1[i];
	for(i=1; i<=m; i++)	f>>v2[i];
	 
	for(i=1; i<=n; i++){
	for(j=1; j<=m; j++){
	
		if(v1[i]==v2[j])
			aux[i][j] = aux[i-1][j-1] +1;
		else
			aux[i][j] = max(aux[i][j-1],aux[i-1][j]);	
	}}	
	
	
	for(i=n; j=m; i!=0){
		if(v1[i]==v2[j]){ 
			result[++k] = v1[i]; 	i--;j--;
		}else {if(aux[i][j-1]>aux[i-1][j])  
				j--;
			else	
				i--;
			}
	}
	g<<k;
	for(i=k; i; i--){
		cout<<result[i];
		g<<result[i]<<' ';
	}
	f.close();
	g.close();

return 0;
}
		
