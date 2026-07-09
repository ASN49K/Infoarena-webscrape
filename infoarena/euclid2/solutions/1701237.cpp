#include <iostream>
using namespace std;
int a,b,m,T;
int main()
{
    cin>>T;
    for (T;T>=1;T--)
        {
    cin>>a>>b;
while (b!=0)
{m=a%b;
    a=b;
    b=m;
}
cout<<a<<'\n';
}}
