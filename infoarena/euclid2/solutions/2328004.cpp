#include<cstdio>
#define M 2000000
int main()
{
	char p[M],e[11];
	int t,a,b,i=-1,r,k,j;
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fread(p,1,M,stdin),t=A();
  	for(t=0,i++;p[i]>='0'&&p[i]<='9';i++)
  		t=t*10+p[i]-'0';
  	while(t--)
  	{
  		for(a=b=0,i++;p[i]>='0'&&p[i]<='9';i++)
  			a=a*10+p[i]-'0';
  		for(i++;p[i]>='0'&&p[i]<='9';i++)
  			b=b*10+p[i]-'0';
    	for(;r=a%b;a=b,b=r);
		for(j=0;b;b/=10,j++)
			e[j]=b%10+'0';
		for(j--;j>=0;j--)
			p[k++]=e[j];
		p[k++]='\n';
	}
	fwrite(p,1,k,stdout);
}
