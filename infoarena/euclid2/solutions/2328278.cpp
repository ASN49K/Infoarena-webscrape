#include<cstdio>
char q[23],e[11],p[1000000];
int i=-1,k;
int A()
{
  	int s=0;
  	for(i++;q[i]>='0'&&q[i]<='9';i++)
  		s=s*10+q[i]-'0';
  	return s;
}
main()
{
	int t,a,b,r,j;
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fgets(q,23,stdin),t=A();
  	while(t--)
  	{
  		fgets(q,23,stdin),i=-1;
    	for(a=A(),b=A();r=a%b;a=b,b=r);
		for(j=0;b;b/=10,j++)
			e[j]=b%10+'0';
		for(j--;j>=0;j--)
			p[k++]=e[j];
		p[k++]='\n';
	}
	fwrite(p,1,k,stdout);
}
