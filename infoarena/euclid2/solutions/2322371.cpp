#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

void ec(unsigned long int x,unsigned long int y)
{
    unsigned long int aux;
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
    unsigned long int n,x,y;
    cin>>n;
    for(unsigned long int i=1;i<=n;i++)
    {
        cin>>x>>y;
        ec(x,y);
    }
}
