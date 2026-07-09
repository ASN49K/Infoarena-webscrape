#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int n,x,y;

int gcd(int a,int b)
{
    if (!b) return a;
    return gcd(b,a%b);
}

int main()
{
    int i,j;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>x>>y;
        cout<<gcd(x,y)<<'\n';
    }
}
