#include<fstream.h>
int n,m,i,j,a[1024],b[1024],u[1024],aa[1024],max=-23,p[1024],pp;
int main()
{ifstream f("cmllsc.in");
ofstream h("cmlsc.out");
f>>n>>m;
for(i=1;i<=n;i++)
	{f>>a[i];
aa[a[i]]=i;}
for(i=1;i<=m;i++)
	f>>b[i];
for(i=n;i>=1;i--)
	{for(j=m;j>=1;j--)
		if(a[i]==b[j])
			{u[i]=1;
		break;}
	for(j=i+1;j<=n;j++)
		if(u[i]!=0&&u[i]+u[j]>u[i]&&aa[a[i]]<aa[a[j]])
	       {  u[i]=u[i]+u[j];
		p[i]=j;}
			 if(u[i]>max)
			{ max=u[i];
	pp=i;}
	}
	h<<max<<"\n";
	for(i=1;i<=max;i++)
		{h<<a[pp]<<" ";
	pp=p[pp];}

return 0;}