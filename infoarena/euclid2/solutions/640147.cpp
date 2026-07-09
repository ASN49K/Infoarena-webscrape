using namespace std;
#include<iostream>
int main()
{
    int a,b,n,i,x,y;
    cout<<"n=";
    cin>>n;
    for(i=1;i<=n;i++)
    {   cout<<"a="<<i;
        cin>>a;
        cout<<"b="<<i;
        cin>>b;
        x=a;
        y=b;

        while(x!=y)
        {if(x>y)
        x=x-y;
        else
        y=y-x;}
        cout<<x<<endl;
    }
    return 0;
}
