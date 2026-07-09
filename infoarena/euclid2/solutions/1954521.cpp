#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
long long cmmdc(long long a,long long b)
{
    long long r;
      while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    long long n,a,b,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
