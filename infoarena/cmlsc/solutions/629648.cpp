#include<cstdio>
int main()
{
	int a[1025],b[1025],s1[1025],s2[1025],*ln,*lv,*aux,i,j,m,n,max;
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++) scanf("%d",&a[i]);
for(i=1;i<=m;i++) scanf("%d",&b[i]);
lv=s1; ln=s2;
lv[1]=1; ln[1]=1;
for(i=1;i<=n;i++)
{
	for(j=1;j<=m;j++)
	{
		if(a[i]==b[j]) ln[j]=lv[j-1]+1; 
		else if(ln[j-1]>lv[j]) ln[j]=ln[j-1]; 
		     else ln[j]=lv[j];
	}
	aux=ln; ln=lv; lv=aux;
}
max=ln[m];
printf("%d\n",max); i=1;j=1;
while(max!=0)
{
	for(j=1;j<=m;j++)
		if(a[i]==b[j]) {printf("%d ",a[i]); max--;}
	i++;
}
return 0;
}
//1 7 3 9 8
//1 8 5 7 9 