#include<cstdio>
#include<algorithm>
using namespace std;
const int M=2000000;
char p[M],q[M];
int t,a,b,c,i=-1,r,k;
int A()
{
  	int s=0;
  	for(i++;p[i]!=' ';i++)
  		s=s*10+p[i]-48;
  	return s;
}
int B()
{
  	int s=0;
  	for(i++;p[i]!='\n';i++)
    	s=s*10+p[i]-48;
  	return s;
}
void S(int b)
{
	char e[100];
	int j,l,o;
	for(j=0;b;b/=10,j++)
		e[j]=b%10+48;
	for(l=j-1;l>=0;l--)
		q[k++]=e[l];
	q[k++]='\n';
}
int main()
{
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),c=fread(p,1,M,stdin),p[c]=0,t=B();
  	while(t--)
  	{
    	for(a=A(),b=B();r=a%b;a=b,b=r);
    	S(b);
	}
  	printf("%s",q);
  	return 0;
}
