#include <iostream>

using namespace std;
int T, a, b;

int euclid(int a, int b)
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
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<'\n';
    }
    return 0;
}
