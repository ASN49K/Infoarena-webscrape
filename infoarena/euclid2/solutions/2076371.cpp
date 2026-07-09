#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a,int b)
{
    if(b==0) return a;
    else return cmmdc(b,a%b);
}



int a,b,r,n,i;
int main()
{
    f>>n;

    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }

    return 0;
}
