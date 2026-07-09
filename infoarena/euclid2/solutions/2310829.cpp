#include<bits/stdc++.h>
using namespace std;
char p[2000000];
int t,i=-1,r,k;
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
	int j;
	for(j=0;b;b/=10,j++)
		e[j]=b%10+48;
	for(j--;j>=0;j--)
		p[k++]=e[j];
	p[k++]='\n';
}
int main()
{
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fread(p,1,M,stdin),t=B();
  	while(t--)
    	S(__gcd(A(),B()));
	fwrite(p,1,k,stdout);
}
