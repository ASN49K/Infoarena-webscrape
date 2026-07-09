#include<stdio.h>
int m,n,a[1025],b[1025],c[1025][1025];
void cit(){
	FILE *f;
	int i;
	f=fopen("cmlsc.in","r");
	fscanf(f,"%d%d",&m,&n);
	for(i=1;i<=m;i++)
		fscanf(f,"%d",&a[i]);
	for(i=1;i<=n;i++)
		fscanf(f,"%d",&b[i]);
	fclose(f);
}
void solve(){
	int i,j;
	if(a[1]==b[1])
		c[1][1]=1;
	else
		c[1][1]=0;
	for(i=2;i<=m;i++)
		if(a[i]==b[1])
			c[i][1]=1;
		else
			c[i][1]=c[i-1][1];
	for(i=2;i<=n;i++)
		if(b[i]==a[1])
			c[1][i]=1;
		else
			c[1][i]=c[1][i-1];
	for(i=2;i<=m;i++)
		for(j=2;j<=n;j++){
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else
				if(c[i-1][j]>c[i][j-1])
					c[i][j]=c[i-1][j];
				else
					c[i][j]=c[i][j-1];
		}
}
void afis(){
	FILE *f;
	f=fopen("cmlsc.out","w");
	int i,j,sol[1025],nr=0;
	fprintf(f,"%d\n",c[m][n]);
	i=m;j=n;
	while(i>0&&j>0){
		if(a[i]==b[j]){
			nr++;
			sol[nr]=a[i];
			i--;
			j--;
		}else
			if(i-1>0&&c[i-1][j]==c[i][j])
				i--;
			else
				j--;
	}
	for(i=nr;i>=1;i--)
		fprintf(f,"%d ",sol[i]);
	fclose(f);
}
int main(){
	cit();
	solve();
	afis();
	return 0;
}
