#include<stdio.h>
int n,m,s[2][1026],t[1026][1026],k=0,u[1026];
void go(int x,int y){
	while(t[x-1][y]==t[x][y])
		x--;
	while(t[x][y-1]==t[x][y])
		--y;
	
	if(t[x-1][y-1])
		go(x-1,y-1);
	u[k++]=s[0][x];
}
void main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&s[0][i]);
	for(int i=1;i<=m;++i)
		scanf("%d",&s[1][i]);

	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[0][i]==s[1][j])
				t[i][j]=t[i-1][j-1]+1;
			else if(t[i-1][j]>t[i][j-1])
				t[i][j]=t[i-1][j];
			else
				t[i][j]=t[i][j-1];
	go(n,m);
	printf("%d \n",k);
	for(int i=0;i<k;++i)
		printf("%d ",u[i]);
}