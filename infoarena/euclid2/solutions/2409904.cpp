#include<cstdio>
char p[0x1000000],r[0x1000000];
unsigned int i,k,n;
inline unsigned int C(unsigned int a,unsigned int b)
{
    for(int t;b;)
        t=b,b=a%b,a=t;
    return a;
}
inline unsigned int A()
{
    unsigned int s=0x0;
    for(;p[i]<0x30;i++);
    for(;p[i]>0x2F;i++)
        s=s*0xA+p[i]-0x30;
    return s;
}
inline void S(unsigned int x)
{
    unsigned int i,d=x>0x3B9AC9FF?0xA:x>0x5F5E0FF?0x9:x>0x98967F?0x8:x>0xF423F?0x7:x>0x1869F?0x6:x>0x270F?0x5:x>0x3E7?0x4:x>0x63?0x3:x>0x9?0x2:0x1;
    for(i=d-1;i>=0;i--,x/=0xA)
        r[k+i]=x%0xA+0x30;
    r[k+d]=0xA,k+=d+1;
}
int main()
{
    freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout),fread(p,0x1,0x1000000,stdin),n=A();
    while(n--)
        S(C(A(),A()));
    fwrite(r,0x1,k,stdout);
    return 0x0;
}
