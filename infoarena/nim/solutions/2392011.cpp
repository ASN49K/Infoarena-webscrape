#include<cstdio>
const int N=20000000;
int n,t,a,l,o,e;
char r[N];
inline int A()
{
  	int s=0;
  	for(;r[o]<'0'||r[o]>'9';o++);
  	for(;r[o]>='0'&&r[o]<='9';o++)
  		s=s*10+r[o]-'0';
  	return s;
}
int main()
{
    freopen("nim.in","r",stdin),freopen("nim.out","w",stdout),fread(r,1,N,stdin),t=A();
    while(t--)
    {
        n=A(),l=0;
        while(n--)
            a=A(),l^=a;
        if(!l)
            r[e++]='N',r[e++]='U';
        else
            r[e++]='D',r[e++]='A';
        r[e++]=10;
    }
    fwrite(r,1,e,stdout);
}
