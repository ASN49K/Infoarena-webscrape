#include <iostream>
using namespace std;

int main()
{
    long long int x, y, k, t;
    cin>>t;
    while(t)
    {
        cin>>x>>y;
        while(y!=0)
        {
            k=x%y;
            x=y;
            y=k;
        }
        cout<<x<<endl;
        t--;
    }
}
