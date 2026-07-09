#include<fstream>
#include<iostream>
using namespace std;
int n,m,l,s[1024],a[1024],b[1024],d[1024][1024];
int main()
{
	int i,j;
	ifstream fin("cmlsc.in");
	fin>>n>>m;
	for(i=1;i<=n;++i)
		fin>>a[i];
	for(i=1;i<=m;i++)
		fin>>b[i];
	fin.close();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j])
				d[i][j]=1+d[i-1][j-1];
			else
				d[i][j]=d[i-1][j]>d[i][j-1]?d[i-1][j]:d[i][j-1];
	for(i=n,j=m;i;)
		if(a[i]==b[j])
			s[++l]=a[i],--i,--j;
		else if(d[i-1][j]>d[i][j-1])
				--i;
			else
				--j;
	FILE *fout=fopen("cmlsc.out","w");
	fprintf(fout,"%d\n",l);
	for(i=l;i;--i)
		fprintf(fout,"%d ",s[i]);
	fclose(fout);
	return 0;
}