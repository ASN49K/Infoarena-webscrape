#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

void ec(int x,int y)
{
    int aux;
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
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        ec(x,y);
    }
}
