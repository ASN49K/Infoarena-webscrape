#include <iostream>

using namespace std;

int main()
{
    int n,a,b,aux;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>b;
        while (b!=0)
        {
            aux=b;
            b=a%b;
            a=aux;
        }
        cout<<a<<endl;
    }
    return 0;
}
