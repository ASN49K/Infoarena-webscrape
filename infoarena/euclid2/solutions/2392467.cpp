#include<cstdio>
#define M 1<<17
char p[M];
int i,k,t;
inline char N()
{
    if(i==M)
        fread(r,1,M,stdin),i=0;
    return p[i++];
}
inline int A()
{
    int x=0;
    char c=N();
    for(;!(c>47&&c<58);c=N());
    for(;c>47&&c<58;c=N())
        x=x*10+c-48;
    return x;
}
int C(int a,int b)
{
    for(int t;b;)
        t=b,b=a%b,a=t;
    return a;
}
inline void S(int x)
{
    int i,d=x>999999999?10:x>99999999?9:x>9999999?8:x>999999?7:x>99999?6:x>9999?5:x>999?4:x>99?3:x>9?2:1;
    for(i=d-1;i>=0;x/=10,i--)
        p[k+i]=x%10+48;
    p[k+d]=10,k+=d+1;
}
int main()
{
	freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fread(p,1,M,stdin),t=A();
  	while(t--)
    	S(C(A(),A()));
	fwrite(p,1,k,stdout);
	return 0;
}
