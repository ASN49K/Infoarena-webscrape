#include <iostream>
#include <fstream>

using namespace std;
int lnko(int a, int b)
{
    while (b!=0)
    {
        int temp =a;
        a=b;
        b=temp%b;
    }
    return a;
}

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    int a,b,n;
    f>>n;
    for (int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<lnko(a,b);
        g<<endl;
    }
    return 0;
}
