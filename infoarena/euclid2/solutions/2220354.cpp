#include<iostream>
using namespace std;
int cmmdc(int &a, int &b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int n,i,a,b;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a>>b;
        cmmdc(a,b);
    }
}
