#include <iostream>

using namespace std;
int a,b,c,r;
int main()
{
    cin>>a>>b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    cout<<a;


    return a;
 }
