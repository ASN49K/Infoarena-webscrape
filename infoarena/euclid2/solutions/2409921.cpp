#include<cstdio>
inline unsigned int C(unsigned int a,unsigned int b)
{
    for(int t;b;)
        t=b,b=a%b,a=t;
    return a;
}
inline unsigned int A()
{
    char inBuffer[0x20000];
    unsigned int p=0x1FFFF,number=0x0;
    (inBuffer[p]>0x2F||(p=-~p&0x1FFFF))||fread(inBuffer,0x1,0x20000,stdin);
    for(;inBuffer[p]>0x2F;)
        number=number*0xA+inBuffer[p]-0x30,(p=-~p&0x1FFFF)||fread(inBuffer,0x1,0x20000,stdin);
    return number;
}
char o[0x100000];
unsigned int p=~0x0;
inline void S(unsigned int x)
{
    unsigned int i,d=x>0x3B9AC9FF?0xB:x>0x5F5E0FF?0xA:x>0x98967F?0x9:x>0xF423F?0x8:x>0x1869F?0x7:x>0x270F?0x6:x>0x3E7?0x5:x>0x63?0x4:x>0x9?0x3:0x2;
    for(i=d;--i;x/=0xA)
        o[p+i]=x%0xA+0x30;
    o[p=p+d]=0xA;
}
int main()
{
    freopen("euclid2.in","r",stdin),freopen("euclid2.out","w",stdout);
    for(unsigned int N=-~A();--N;)
        S(C(A(),A()));
    fwrite(o,0x1,p,stdout);
    return 0x0;
}
