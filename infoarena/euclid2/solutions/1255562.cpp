#include <iostream>

using namespace std;

int main()
{
    int a,b,r;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    r=a%b;
    while (r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    cout<<"cmmdc="<<b;

    return 0;
}
