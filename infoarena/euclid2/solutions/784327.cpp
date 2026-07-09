#include <iostream>
using namespace std;

int cmmdc(int a, int b)
{
    int c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<cmmdc(a,b);
    cout.flush();
    return 0;
}
