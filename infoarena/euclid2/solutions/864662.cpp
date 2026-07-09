#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"a="<<a;
    cin>>a;
    cout<<"b="<<b;
    cin>>b;
    while(a!=b)
        if(a>b)
            a-=b;
        else
            b-=a;
        cout<<"cmmdc este "<<a;
    return 0;
}
