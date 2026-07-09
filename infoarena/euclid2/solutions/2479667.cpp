#include <fstream>

using namespace std;
int cmmdc(int a,int b)
{
    int r=a%b;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int t,a,b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
