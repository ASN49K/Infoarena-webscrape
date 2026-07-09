#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
    ifstream f;
    ofstream g;
    f.open("euclid2.in");
    g.open("euclid2.out");
    int t;
    f>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        f>>a>>b;
        g<<gcd(a,b)<<"\n";
    }
    f.close();
    g.close();
    
    return 0;
}