#include<stdio.h>
int a[1025],b[1025],t[1025][1025]={0},ut[1025]={0};
int n,m;
int max(int a,int b)
{
	if(a>b)
		return a;
	else 
		return b;
}
void go(int i,int j);
int main()
{
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	
	for(int i=0;i<n;i++)
	{
		if(i)
		{
			if(a[i]==b[0])
				t[0][i]=t[0][i-1]+1;
			else
				t[0][i]=t[0][i-1];
		}
		else
			if(a[0]==b[0])
				t[0][0]=1;
	}
	for(int i=1;i<m;i++)
	{
		if(a[0]==b[i])
			t[i][0]=t[i-1][0]+1;
		else
			t[i][0]=t[i-1][0];
	}
	
	for(int i=1;i<m;i++)
		for(int j=1;j<n;j++)
		{
			if(a[j]==b[i])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i][j-1],t[i-1][j]);
		}
	go(m-1,n-1);
	printf("%d\n",t[m-1][n-1]);
	for(int i=1;i<=t[m-1][n-1];i++)
		printf("%d ",ut[i]);
	return 0;
}
void go(int i,int j)
{	if(t[i][j]!=t[i-1][j])
	{
	
	while(t[i][j]==t[i][j-1])
		j--;
	ut[t[i][j]]=a[j];
	if(i>0 && j>0 &&t[i-1][j-1]>0)
	go(i-1,j-1);
	}
	else
		go(i-1,j);
}