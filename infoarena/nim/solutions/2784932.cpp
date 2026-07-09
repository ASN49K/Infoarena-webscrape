#include<iostream>
#include<fstream>
using namespace std;
int i,t,n,s,x;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        cin>>n;
        s=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            s^=x;
        }
        if(s==0)
        {
            cout<<"NU";
        }
        else cout<<"DA";
    }
}
