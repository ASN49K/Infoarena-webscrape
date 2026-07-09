#include <iostream>

using namespace std;


int euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    int t, a, b;

    for(int i=0; i<t; i++)
    {
        cin>>a>>b;
        cout<<euclid(a, b)<<"\n";
    }
}