#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

void ec(unsigned long a,unsigned long b)
{
    if(a==b)
        cout<<a<<endl;
    else
    {if(a>b)
        ec(a-b,b);
    if(a<b)
        ec(a,b-a);}
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
