#include <iostream>

using namespace std;

int div(int a, int b)
{
    if(a == 1 || b == 1) return 1;
    if (a == b) return a;
    return a < b ? div(a , b - a):  div(a - b , b);
}


int main()
{
    int T;
    cin>>T;
    int a,b;
    for(int i = 0;i < T;i++)
    {
        cin>>a>>b;
        cout<<div(a,b);
    }
    return 0;
}
