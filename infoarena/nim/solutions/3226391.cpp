#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
#define Z 2048
int c,n,i,j,p=Z,q;
char s[Z],t[Z];
char B()
{
    if(p==Z)
        F.read(s,Z),p=0;
    return s[p++];
}
int A()
{
    int n=0;
    char c;
    for(c=B();!isdigit(c);c=B());
    for(;isdigit(c);n=n*10+c-48,c=B());
    return n;
}
void D()
{
    if(q==Z)
        G.write(t,Z),q=0;
}
int main()
{
    for(c=A();c--;j?t[q++]='D',D(),t[q++]='A',D():(t[q++]='N',D(),t[q++]='U',D()),t[q++]='\n',D())
        for(n=A(),j=0;n--;i=A(),j^=i);
    return G.write(t,q),0;
}
