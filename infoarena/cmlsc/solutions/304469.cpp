#include<stdio.h>
#define nmax 1050
int max(int,int);
int n,m,a[nmax],b[nmax],d[nmax][nmax],s[nmax],c;
int main(){
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			if(a[i]==b[j])
				d[i][j]=d[i-1][j-1]+1;
			else
				d[i][j]=max(d[i-1][j],d[i][j-1]);
	i=n;
	j=m;
    while(i)
		if(a[i]==b[j]){
			c++;
			s[c]=a[i];
			i--;
			j--;
		}
		else 
			if(d[i-1][j]<d[i][j-1])
				j--;
			else i--;
	printf("%d\n",c);
	for(i=c;i;i--)
		printf("%d ",s[i]);
	return 0;
}
int max(int a,int b){
	if(a>b)return a;
	else return b;
}