#include<bits/stdc++.h>

using namespace std;


int x[1100],y[1100];
int c[1100][1100],d[1100];
int n,m,k=1;

int cmlsc(){
	for(int i=0;i<=n;i++){
		c[i][0]=0;	
	}
	for(int i=0;i<=m;i++){
		c[0][i]=0;	
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(x[i]==y[j]){
				c[i][j]=c[i-1][j-1]+1;
				d[k]=x[i];
				k++;
			}
			else
				c[i][j]=max(c[i][j-1],c[i-1][j]);
	return c[n][m];
}

int main(){
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=m;i++)
		cin>>y[i];
	cout<<cmlsc()<<'\n';
	for(int i=1;i<=c[n][m];i++)
		cout<<d[i]<<" ";
	return 0;
}
