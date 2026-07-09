#include<bits/stdc++.h>
using namespace std;
const int M=2000000;
char p[M],*h,*w;
bool d[255];
int t,a,b;
void P()
{
	int a=fread(p,1,M,stdin);
  	p[a]=0,h=p;
  	memset(d,0,sizeof d);
  	for(int i='0';i<='9';++i)
    	d[i]=true;
  	w=h;
}
int I()
{
  	int s=0;
  	for(;d[*h];++h)
    	s=s*10+(*h)-'0';
  	return s;
}
int J()
{
  	int s=0;
  	for(++h;d[*h];++h)
    	s=s*10+(*h)-'0';
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
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),P(),t=I();
  	while(t--)
    	a=I(),b=J(),N(__gcd(a, b));
  	fwrite(p,1,w-p,stdout);
}
