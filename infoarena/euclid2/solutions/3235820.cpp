#include<bits/stdc++.h>
using namespace std;
ifstream F("euclid2.in");
ofstream G("euclid2.out");
#define Z 2048
int n,a,b,p=Z,q,m,k,c[10];
char s[Z],t[Z];
inline char A()
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
inline void C()
{
    if(q==Z)
        G.write(t,Z),q=0;
}
int main()
{
    for(n=B();n--;t[q++]='\n',C()) {
        for(a=B(),b=B(),m=__gcd(a,b),k=0;m;c[k++]=m%10,m/=10);
        for(;k;t[q++]=c[--k]+48,C());
    }
    return G.write(t,q),0;
}
