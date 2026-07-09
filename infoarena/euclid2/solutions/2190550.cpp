#include <iostream>

using namespace std;


int main()
{
    int a,b;
    cin>>a>>b;

    for(int i=a;i>=1;i--)
        if(a%i==0 && b%i==0)
        {
            cout<<i;
            i=0;
         }



    return 0;
}
