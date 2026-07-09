#include <iostream>

using namespace std;

int dout(int a, int b)
{
    if(b>a)
        return dout(a,b%a);
    if(b<a)
        return dout(b,a%b);
    else return a;

}


    int main()
    {
        int a,b;
        cin>>a>>b;
        cout<<dout(a,b);

        return 0;
    }
