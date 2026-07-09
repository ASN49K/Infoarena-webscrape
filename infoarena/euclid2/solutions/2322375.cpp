#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

void ec(unsigned long int a,unsigned long int b)
{
    if(b==0)
        cout<<a<<'\n';
    else
    ec(b,a%b);
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
