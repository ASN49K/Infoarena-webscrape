#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<fstream>
#define M 2000000
using namespace std;
string p("");
char s[M];
int t,a,b,i=-1;
int A()
{
  	int n=0;
  	for(i++;s[i]!=' '&&s[i]!='\n';i++)
  		n=n*10+s[i]-48;
  	return n;
}
int main()
{
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fread(s,1,M,stdin),t=A();
  	while(t--)
  	{
    	for(a=A(),b=A();!b;a=b,b=a%b);
    	string r=to_string(a);
    	p+=r+"\n";
	}
	printf("%s",p.c_str());
}
