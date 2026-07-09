#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int t, a, b, i;
int cmmdc(int a, int b)
{
    int r;
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
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a, b)<<endl;
    }
    return 0;
}
