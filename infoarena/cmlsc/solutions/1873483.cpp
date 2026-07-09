#include <bits/stdc++.h>
using namespace std;
long long c[10000][10000],a[10000],b[10000],i,j,n,m,k,huyax[10000];
int main(){
	ifstream cin("clmsc.in");
	ofstream cout("cmlsc.out");
	cin>>n>>m;
	for (i=1;i<=n;i++)
	cin>>a[i];
	for (j=1;j<=m;j++)
	cin>>b[j];
	for (i=1;i<=n;i++)
	 for (j=1;j<=m;j++){
	      	if (a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
	 	    else c[i][j]=max(c[i-1][j],c[i][j-1]);
	 		} 
 cout<<c[n][m]<<'\n';
    i=n;
    j=m;
    while (c[i-1][j]!=0 && c[i][j-1]!=0){
    	if (c[i][j]==c[i-1][j]) i--;
    	else if (c[i][j]==c[i][j-1]) j--;
    	else if (c[i][j]==1+c[i-1][j-1]) {
   huyax[k]=a[i];
   k++;		
    		i--;
    		j--;
		}
     	
	}
huyax[k]=a[i];
    for (i=k;i>=0;i--)
    cout<<huyax[i]<<" ";

	return 0;
}

