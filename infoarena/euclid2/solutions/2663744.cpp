#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int gcd(int a,int b)
{
    int rest;
    while(b)
    {
        rest=b;
        b=a%b;
        a=rest;
    }
    return a;
}
int main()
{
    int n,a,b,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<gcd(a,b)<<"\n";
    }
    return 0;
}
