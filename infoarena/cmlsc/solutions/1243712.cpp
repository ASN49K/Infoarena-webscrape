#include<iostream>
#include<fstream>
#define max(a,b) (a>b)?a:b
#define  MAX 1024
using namespace std;


ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int v1[MAX], v2[MAX], aux[MAX][MAX], result[MAX], k=0;
int i, j, n , m ;	

int main(){
	
	f>>n>>m;
 	
	for(i=0; i<n; i++) 	{f>>v1[i];}
	for(i=0; i<m; i++)	{f>>v2[i];}
	 
	for(i=1; i<=n; i++){
	for(j=1; j<=m; j++){

		if(v1[i]==v2[j]) {
			aux[i][j] = aux[i-1][j-1] +1;
		}else{
			aux[i][j] = max(aux[i][j-1],aux[i-1][j]);	
			}	
	}}

	g<<aux[n][m];		
	
	i = n; j = m;	
	while(i!=0 & j!=0){
		if(v1[i]==v2[j]) {
			result[++k] = v1[i];
			i--;j--;
		}else{ if(aux[i][j-1]>aux[i-1][j])  
			j--;
			else	
			i--;
		}
	}

	f.close();
	g.close();

return 0;
}
		
