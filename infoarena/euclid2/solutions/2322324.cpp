#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

void ec(long x,long y)
{
    long aux;
    while(y)
    {
        aux=x%y;
        x=y;
        y=aux;
    }
    cout<<x<<endl;
}
int main()
{
    long n,x,y;
    cin>>n;
    for(long i=1;i<=n;i++)
    {
        cin>>x>>y;
        ec(x,y);
    }
}
