#include<cstdio>
#include<cctype>
#define M 2000000
char p[M],e[11];
int i=-1,k,j;
int A()
{
  	int s=0;
  	for(i++;isdigit(p[i]);i++)
  		s=s*10+p[i]-'0';
  	return s;
}
int main()
{
	int t,a,b,r;
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fread(p,1,M,stdin),t=A();
  	while(t--)
  	{
    	for(a=A(),b=A();r=a%b;a=b,b=r);
		for(j=0;b;b/=10,j++)
			e[j]=b%10+'0';
		for(j--;j>=0;j--)
			p[k++]=e[j];
		p[k++]='\n';
	}
	fwrite(p,1,k,stdout);
}
