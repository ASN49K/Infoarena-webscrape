#include <fstream>
using namespace std;
ifstream cin("euclid.in");
ofstream cout("euclid.out");

int n,i,x,y;

int cmmdc(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        cout<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
