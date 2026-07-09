#include <bits/stdc++.h>

using namespace std;
ifstream f("cmmdc.in");
ofstream g("cmmdc.out");
int main()
{
    long long cb,ca,a,b,r;
    f>>a>>b;
    ca=a;
    cb=b;
    r=ca%cb;
    while(ca*cb!=0)
    {
        ca=cb;
        cb=r;
        r=ca%cb;
    }
    if(cb==1)
        g<<"0";
    else
    {
        while(a!=b)
            if(a>b)
                a=a-b;
            else
                b=b-a;
        g<<a;
    }
    return 0;
}
