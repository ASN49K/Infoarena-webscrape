#include <iostream>
#include <cmath>
using namespace std;
int a,b,x,i;
int main()
{
    cin>>a>>b;
    x=a%b;
    while(x!=0)
    {
        a=b;
        b=x;
        x=a%b;
    }
    if(b==1) cout<<"PIE";
    else cout<<"NOPIE";
    return 0;
}
