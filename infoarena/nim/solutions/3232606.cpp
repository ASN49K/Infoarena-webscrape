#include<fstream>
using namespace std;
ifstream F("nim.in");
ofstream G("nim.out");
#define Z 2048
int m,n,i,j,p=Z,q;
char s[Z],t[Z];
char A()
{
    if(p==Z)
        F.read(s,Z),p=0;
    return s[p++];
}
int B()
{
    char c;
    for(c=A();!isdigit(c);c=A());
    int n=0;
    for(;isdigit(c);n=n*10+c-48,c=A());
    return n;
}
void C()
{
    if(q==Z)
        G.write(t,Z),q=0;
}
int main()
{
    for(m=B();m--;j?t[q++]='D',C(),t[q++]='A':(t[q++]='N',C(),t[q++]='U'),C(),t[q++]='\n',C())
        for(n=B(),j=0;n--;i=B(),j^=i);
    return G.write(t,q),0;
}
