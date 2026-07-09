#include <iostream>
using namespace std;
int cmmdc(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{ int a,b;
    cin>>a>>b;
    cout<<cmmdc(a,b)<<endl;
}
