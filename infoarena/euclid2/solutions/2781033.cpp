#include<bits/stdc++.h>
using namespace std;
#define M 2000000
char p[M];
int i=-1,k,t;
inline int A()
{
  	int s=0;
  	for(i++;p[i]>47;i++)
  		s=s*10+p[i]-48;
  	return s;
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
    	S(__gcd(A(),A()));
	fwrite(p,1,k,stdout);
}
