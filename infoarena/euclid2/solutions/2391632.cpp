#include<cstdio>
#define M 2000000
char p[M];
int i=-1,k,t;
inline int A()
{
  	int s=0;
  	for(i++;p[i]>='0'&&p[i]<='9';i++)
  		s=s*10+p[i]-'0';
  	return s;
}
inline int C(int a,int b)
{
    for(int t;b;)
        t=b,b=a%b,a=t;
    return a;
}
inline void S(int x)
{
    int i,d=x<10?1:x<100?2:x<1000?3:x<10000?4:x<100000?5:x<1000000?6:x<10000000?7:x<100000000?8:x<1000000000?9:10;
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
}
