#include <bits/stdc++.h>

using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int cmmdc(int a,int b)///cel mai mare divizor comun
{
    if(!b)
        return a;
    return cmmdc(b,a%b);
}
int main()
{int n,a,b;
f>>n;
for(int i=1;i<=n;i++){
    f>>a>>b;
    g<<cmmdc(a,b)<<'\n';
}
    return 0;
    f.close();
    g.close();
}