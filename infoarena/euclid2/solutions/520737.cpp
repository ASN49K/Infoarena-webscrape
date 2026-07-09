#include<fstream.h>
#include<iostream.h>
ifstream f("euclid.in");
ofstream g("euclid.out");
int T,i;
long a,b,c,d,s,t,e; long long euclid(long long a,long long b,long long &s, long long&t)
{ long long r,q,s1,s2,t1,t2;
if(b!=0)
{
	s=1;
	t=0;
	return a;}
	s1=1;
	s2=0;
	t1=0;
	t2=1;
	r=a%b;
	q=a/b;
	while(r)
	{ s=s1-s2*q;
	  s1=s2;
	  s2=s;
	  t=t1-t2*q;
	  t1=t2;
	  t2=t;
	  a=b;
	  b=r;
	  r=a%b;
	  q=a/b;}
	  return b;}
int main ()
{
	f>>T;
	for(i=1;i<=T;i++)
	{
		f>>a>>b>>c;
		// if(b==0) g<<"1 0"<<'\n';//
		d= euclid(a,b,s,t);
		if(c%d)
			g<<"0 0"<<'\n';
		else e=c/d;
		g<<s*e<<" "<<t*e<<'\n';}
	g.close();
	f.close();
}

	