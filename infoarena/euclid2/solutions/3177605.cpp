#include <iostream>

using namespace std;

int main()
{
    int n,a,b,r,cx,cy,x,y;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b;
        while (b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<'\n';
    }


    return 0;
}
