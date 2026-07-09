#include<iostream>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        while(a!=0)
        {
            int r=b%a;
            b=a;
            a=r;
        }
        cout<<b<<'\n';
    }
}
