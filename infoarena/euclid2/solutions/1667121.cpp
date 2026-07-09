#include <iostream>

using namespace std;

int main()
{
    int T,a,b,c,i;
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>a;
        cin>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        cout<<a<<endl;
    }
    return 0;
}
