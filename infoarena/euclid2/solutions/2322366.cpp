#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

void ec(unsigned long long x,unsigned long long y)
{
    unsigned long long aux;
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
    unsigned long long n,x,y;
    cin>>n;
    for(unsigned long long i=1;i<=n;i++)
    {
        cin>>x>>y;
        ec(x,y);
    }
}
