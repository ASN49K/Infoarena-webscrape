#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

void ec(unsigned long x,unsigned long y)
{
    unsigned long aux;
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
    unsigned long n,x,y;
    cin>>n;
    for(unsigned long i=1;i<=n;i++)
    {
        cin>>x>>y;
        ec(x,y);
    }
}
