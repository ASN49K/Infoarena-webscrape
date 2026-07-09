#include <iostream>
#include <fstream>
using namespace std;
int CMMDC(int a, int b);
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int k,a,b;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>a>>b;
        cout<<CMMDC(a,b)<<"\n";
    }
    return 0;
}
int CMMDC(int a, int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
