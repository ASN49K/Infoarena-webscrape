#include<stdio.h>

FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");

int s1[1025],s2[1025];
int sol[1025][1025];
int n,m;

inline int max(int a,int b){return(a>b?a:b);}

void solve(){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(s1[i]==s2[j]) sol[i][j]=1+sol[i-1][j-1];
			else sol[i][j] = max(sol[i-1][j],sol[i][j-1]);
		}
	}
}

void print(int i,int j){

	if(i>0 && j>0)
		if(s1[i]==s2[j])
			{print(i-1,j-1);fprintf(g,"%d ",s1[i]);}
		else if(sol[i-1][j]>sol[i][j-1]) print(i-1,j);
		else print(i,j-1);
}

int main(){

	fscanf(f,"%d %d",&n,&m);
	int i;
	for(i=1;i<=n;i++) fscanf(f,"%d",s1+i);
	for(i=1;i<=m;i++) fscanf(f,"%d",s2+i);
	
	solve();
	fprintf(g,"%d\n",sol[n][m]);
	print(n,m);

	return 0;
}


	