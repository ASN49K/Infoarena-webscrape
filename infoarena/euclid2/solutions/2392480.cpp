#include<cstdio>
const int M=1<<17,P=10000000;
char p[M],r[P];
int i,k,t;
inline char N()
{
    if(i==M)
        fread(p,1,M,stdin),i=0;
    return p[i++];
}
inline int A()
{
    int x=0;
    char c=N();
    while(!(c>='0'&&c<='9')&&c!='-')
        c=N();
    while(c>='0'&&c<='9')
        x=x*10+c-'0',c=N();
    return x;
}
inline int C(int a,int b)
{
    for(int t;b;)
        t=b,b=a%b,a=t;
    return a;
}
inline void S(int x)
{
    int i,d=x>999999999?10:x>99999999?9:x>9999999?8:x>999999?7:x>99999?6:x>9999?5:x>999?4:x>99?3:x>9?2:1;
    for(i=d-1;i>=0;x/=10,i--)
        r[k+i]=x%10+48;
    r[k+d]=10,k+=d+1;
}
int main()
{
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),t=A();
  	while(t--)
    	S(C(A(),A()));
	fwrite(r,1,k,stdout);
	return 0;
}
