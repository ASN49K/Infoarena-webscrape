#include<cstdio>
#define M 2000000
char p[M];
int t,a,b,i=-1,r,k;
int A(char c)
{
  	int s=0;
  	for(i++;p[i]!=c;i++)
  		s=s*10+p[i]-48;
  	return s;
}
void S(int b)
{
	char e[100];
	int j;
	for(j=0;b;b/=10,j++)
		e[j]=b-10*(b/10)+48;
	for(j--;j>=0;j--)
		p[k++]=e[j];
	p[k++]='\n';
}
int main()
{
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fread(p,1,M,stdin),t=A('\n');
  	while(t--)
  	{
    	for(a=A(' '),b=A('\n');r=a%b;a=b,b=r);
    	S(b);
	}
	fwrite(p,1,k,stdout);
}
