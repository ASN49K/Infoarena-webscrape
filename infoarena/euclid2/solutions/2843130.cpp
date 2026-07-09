#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int a,b,r;
    while(t--)
    {
        cin>>a>>b;
        r = a%b;
        while(r != 0)
        {
            a = b;
            b = r;
            r = a%b;
        }
        cout << b << '\n';

    }
    return 0;
}
