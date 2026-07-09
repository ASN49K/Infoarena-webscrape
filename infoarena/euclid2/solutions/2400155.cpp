//#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a,b,c,n,i;
int lnko(int a,int b)
{
    while(a!=b)
    {
        a=abs(a-b);
        b=abs(b-a);
    }
    return a;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a>>b;
        cout<<lnko(a,b)<<"\n";
    }
    return 0;
}
