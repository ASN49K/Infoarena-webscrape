#include <fstream>
using namespace std;
int a,b,m,T;
int main()
{   ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
    cin>>T;
    for (T;T>=0;T--)
        {
    cin>>a>>b;
while (b!=0)
{m=a%b;
    a=b;
    b=m;
}
cout<<a;
}}
