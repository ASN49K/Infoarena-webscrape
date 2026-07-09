#include<cstdio>
#include<string>
using namespace std;
const int M=2000000;
char p[M];
string q("");
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
int main()
{
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),c=fread(p,1,M,stdin),p[c]=0,t=B();
  	while(t--)
  	{
    	for(a=A(),b=B();r=a%b;a=b,b=r);
    	q+=to_string(b)+"\n";
	}
  	printf("%s",q);
  	return 0;
}
