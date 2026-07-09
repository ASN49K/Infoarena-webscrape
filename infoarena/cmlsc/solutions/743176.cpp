#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int surp,sur2,sf1,sf2,in,i1,j1,maxi,n,m,nr,i,j,ap1[300],ap2[300],a[1026],b[1026],d[1026],d1[1026],d2[1026],l[1026][1026],vp[1026],vs[1026],v[1026];
int main()
{
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
{
	scanf("%d",&a[i]);
	ap1[a[i]]++;
}
for(i=1;i<=m;i++)
{
	scanf("%d",&b[i]);
	ap2[b[i]]++;
}
for(i=1;i<=256;i++)
	if(ap1[i]>0&&ap2[i]>0)
	{
		if(ap1[i]<ap2[i])
		{
			nr=0;
			for(j=1;j<=m;j++)
				if(b[j]==i)
				{
					nr++;
					d2[j]=1;
					if(nr==ap2[i]-ap1[i]) break;
				}
		}
		else
		if(ap1[i]>ap2[i])
		{
			nr=0;
			for(j=1;j<=n;j++)
				if(a[j]==i)
				{
					nr++;
					d1[j]=1;
					if(nr==ap1[i]-ap2[i]) break;
				}
		}
	}
nr=0;
for(i=1;i<=n;i++)
	if(d1[i]==0)
	{
		nr++;
		d[nr]=a[i];
	}
n=nr;
memset(a,0,sizeof(a));
for(i=1;i<=n;i++)
	a[i]=d[i];
nr=0;
for(i=1;i<=m;i++)
	if(d2[i]==0)
	{
		nr++;
		d[nr]=b[i];
	}
m=nr;
memset(b,0,sizeof(b));
for(i=1;i<=m;i++)
	b[i]=d[i];
/*for(i=1;i<=n;i++)
	printf("%d ",a[i]);
printf("\n");
for(i=1;i<=m;i++)
	printf("%d ",b[i]);*/
surp=0;
i=1;
while(a[i]==b[i])
{
	surp++;
	vp[surp]=a[i];
	i++;
}
in=i;
i=n;
j=m;
while(a[i]==b[j]&&i>in&&j>in)
{
	sur2++;
	vs[sur2]=a[i];
	i--;
	j--;
}
sf1=i;
sf2=j;
for(i=in;i<=sf1;i++)
	for(j=in;j<=sf2;j++)
	{
		if(a[i]==b[j]) l[i][j]=l[i-1][j-1]+1;
		else l[i][j]=max(l[i-1][j],l[i][j-1]);
		if(l[i][j]>maxi)
		{
			maxi=l[i][j];
			i1=i;
			j1=j;
		}
	}
printf("%d\n",surp+sur2+maxi);
if(surp>0)
	{
	for(i=1;i<=surp;i++)
		printf("%d ",vp[i]);
}
nr=maxi+1;
while(i1>0&&j1>0)
{
	if(a[i1]==b[j1])
	{
		nr--;
		v[nr]=a[i1];
		i1--;
		j1--;
		if(nr==1) break;
	}
	else
	{
		if(l[i1-1][j1]>l[i1][j1-1]) i1--;
		else j1--;
	}
}
for(i=1;i<=maxi;i++)
	printf("%d ",v[i]);
if(sur2>0)
{
	for(i=1;i<=sur2;i++)
		printf("%d ",vs[i]);
}
return 0;
}
