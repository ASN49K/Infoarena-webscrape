#include<iostream>
using namespace std;
int main()
{
    int a,b,t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        while(a!=b)
        {
            if(a>b)
            a=a-b;
            else
            b=b-a;
        }
        cout<<a<<endl;
    }
    return 0;
}