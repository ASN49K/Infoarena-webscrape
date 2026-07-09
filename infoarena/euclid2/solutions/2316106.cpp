#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int cmmdc(int a,int b)
{
    if(!a)
        return b;
    return cmmdc(b%a,a);
}
int main()	
{
    int n,a,b;
    in>>n;
    while(n--)
    {
        in>>a>>b;
        out<<cmmdc(min(a,b),max(a,b))<<"\n";
    }
    return 0;
}
