#include <iostream>
using namespace std;
int cmmdc(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
int main()
{
    int n,a,b;
    cin>>n;
    for(;n;n--)
    {cin>>a>>b;
    cout<<cmmdc(a,b);
    }
    return 0;
}
