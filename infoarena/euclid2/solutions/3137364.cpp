#include <iostream>

using namespace std;

int main()
{
    int a, b, cmmdc, auxa, auxb;
    cin>>a>>b;
    //auxa=a;
    //auxb=b;
    while(a!=b)
    {
        //cout<<a<<" "<<b<<endl;
        if(a<b)
        {
            b=b-a;
            continue;
        }
        if(a>b)
        {
            a=a-b;
            continue;
        }
    }
    //cout<<endl;
    cout<<a;
    return 0;
}
