#include <iostream>
using namespace std;

int main()
{
    int a,b;
    a=4;
    b=6;
    while(a!=0,b!=0)
    {if(a>b)
    {
        a=a-b;
    }
    else
    {
        b=b-a;
    }
    }
    if(a==0)
    {
        cout<<"Cmmdc este: "<<b;
    }
    else
    {
        cout<<"Cmmdc este: "<<a;

    }
}
