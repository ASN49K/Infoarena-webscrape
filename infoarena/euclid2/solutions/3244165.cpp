#include <iostream>
#include <algorithm>
using namespace std;
int rasp(int &a, int &b)
{
    while (a!=b)
    {
        if (a>b)
            a-=b;
        else
            b-=a;
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    int a,b;
    for (int i=1; i<=n; i++)
    {
        cin>>a>>b;
        cout<<rasp(a,b)<<'\n';
    }
    return 0;
}
