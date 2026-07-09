#include<fstream.h>

int maxim(int a,int b, int c)
{
 int max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;
 return max;
}

int main()
{
 ifstream fin("cmlsc.in");
 ofstream fout("cmlsc.out");
 int n,m,a[1025],b[1025],s[1025][1025],i,j,max,aux[1025],k=0;
 fin>>n>>m;
 for(i=1;i<=n;i++)
	fin>>a[i];
 for(i=1;i<=m;i++)
	fin>>b[i];
 if(n>m)
	max=n;
 else
	max=m;
 for(i=0;i<=max;i++)
	{s[0][i]=0;s[i][0]=0;}
 for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
		if(a[i]==b[j])
			s[i][j]=s[i-1][j-1]+1;
		else
			s[i][j]=maxim(s[i][j-1],s[i-1][j],s[i-1][j-1]);
 fout<<s[n][m]<<"\n";
 i=n;j=m;
 while(i>0 && j>0)
	{
		if(maxim(s[i][j-1],s[i-1][j],s[i-1][j-1])==s[i-1][j-1] && maxim(s[i][j-1],s[i-1][j],s[i-1][j-1])!=s[i][j])
			{aux[++k]=a[i];i--;j--;}
		else   {
				if(maxim(s[i-1][j],s[i][j-1],s[i-1][j-1])==s[i-1][j])
					i--;
				else	if(maxim(s[i-1][j],s[i][j-1],s[i-1][j-1])==s[i][j-1])
						j--;
			}
	}
 for(i=k;i>=1;i--)
	fout<<aux[i]<<" ";
return 0;
}