#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    unsigned int r;
    if(a>b)
    {
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    else
    {
        while(a!=0)
        {
            r=b%a;
            b=a;
            a=r;
        }
        return b;
    }
}

int main()
{
    int x,y,n,i;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        cout<<cmmdc(x,y)<<endl;
    }
    return 0;
}
