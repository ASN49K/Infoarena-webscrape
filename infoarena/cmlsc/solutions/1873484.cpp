#include <bits/stdc++.h>
using namespace std;
int c[1050][1050],a[1050],b[1050],i,j,n,m,k,hx[1050];
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
   hx[k]=a[i];
   k++;		
    		i--;
    		j--;
		}
     	
	}
hx[k]=a[i];
    for (i=k;i>=0;i--)
    cout<<hx[i]<<" ";

	return 0;
}

