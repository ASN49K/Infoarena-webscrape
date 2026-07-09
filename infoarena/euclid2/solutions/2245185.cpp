#include <iostream>
using namespace std;
int a,b,r;
int main()
{   cin>>a>>b;
    while(b)
    {   r=a%b;
        a=b;
        b=r;
    }
    cout<<a;
    return 0;
}
