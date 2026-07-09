#include <iostream>

using namespace std;

int main()
{
    int t,a,b,i,aux;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b;
        while(b!=0)
        {
            a%=b;
            aux=a;
            a=b;
            b=aux;
        }
        cout<<a<<'\n';
    }
    return 0;
}
