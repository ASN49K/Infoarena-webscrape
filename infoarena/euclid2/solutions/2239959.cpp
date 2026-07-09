#include <iostream>

using namespace std;

int main()
{
    int a,b,t,v[100];
    cin>>t;
    for (int i=0; i<t; i++)
    {
        cin>>a>>b;
        while (a!=b)
        {
            if (a>b) a=a-b;
            else b=b-a;
        }
    v[i]=a;
    }
    for (int i=0;i<t;i++)
    cout<<v[i]<<endl;
    return 0;
}
