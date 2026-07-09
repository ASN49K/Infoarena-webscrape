#include<bits/stdc++.h>

using namespace std;

enum Direction {up, left1, diagonal};

int x[1100],y[1100];
int c[1100][1100];
int n,m,k=1;
Direction dir[1100][1100];

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
				dir[i][j]=diagonal;
			}
			else
				if(c[i][j-1]>=c[i-1][j])
					c[i][j]=c[i][j-1],dir[i][j]=left1;
				else c[i][j]=c[i-1][j],dir[i][j]=up;
	return c[n][m];
}

void drumul(int a,int b){
	if(a==0 || b==0) return;
	if(dir[a][b]==diagonal){
		drumul(a-1,b-1);
		cout<<x[a]<<" ";
	}
	else if(dir[a][b]==up) 
			drumul(a-1,b);
		else drumul(a,b-1); 
}

int main(){
	//ifstream cin("cmlsc.in");
	//ofstream cout("cmlsc.out");
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=m;i++)
		cin>>y[i];
	cout<<cmlsc()<<'\n';
	drumul(n,m);
	return 0;
}
