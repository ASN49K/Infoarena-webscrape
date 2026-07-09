#include<cstdio>
const int M=1000000;
int n,t,a,l,o,e;
char r[M];
inline char N()
{
    if(o==M)
        fread(r,1,M,stdin),o=0;
    return r[o++];
}
inline int A()
{
    int x=0;
    char c=N();
    while(!(c>='0'&&c<='9'))
        c=N();
    while(c>='0'&&c<='9')
        x=x*10+c-'0',c=N();
    return x;
}
int main()
{
    freopen("nim.in","r",stdin),freopen("nim.out","w",stdout),t=A();
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
