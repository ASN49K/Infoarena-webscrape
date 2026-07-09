#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout("euclid2.out");

int cmmdc (int a,int b)
{
    while (b!=0)
    {
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int i,n,a,b;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<cmmdc (a,b)<<"\n";
    }
    return 0;
}
