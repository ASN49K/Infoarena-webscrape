#include<cstdio>
#include<string>
#define M 2000000
using namespace std;
char s[M];
int i=-1;
int A()
{
  	int n=0;
  	for(i++;s[i]!=' '&&s[i]!='\n';i++)
  		n=n*10+s[i]-48;
  	return n;
}
int main()
{
	int t,a,b,r;
	string p("");
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fread(s,1,M,stdin),t=A();
  	while(t--)
  	{
    	for(a=A(),b=A(),r=a%b;r;a=b,b=r,r=a%b);
    	p+=to_string(b)+"\n";
	}
	printf("%s",p.c_str());
}
