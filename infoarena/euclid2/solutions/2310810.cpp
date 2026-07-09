#include<cstdio>
#include<algorithm>
using namespace std;
const int M=2000000;
char p[M],*h,*w;
int t,a,b,c,i=-1,r;
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
void N(int x)
{
  	char *o;
  	for(o=w;x;x/=10) 
    	*(w++)=x%10+'0';
  	reverse(o,w),*(w++)='\n';
}
int main()
{
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),c=fread(p,1,M,stdin),p[c]=0,h=p,t=B(),w=h;
  	while(t--)
  	{
    	for(a=A(),b=B();r=a%b;a=b,b=r);
    	N(b);
	}
  	fwrite(p,1,w-p,stdout);
  	return 0;
}
