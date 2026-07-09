#include <iostream>
#include <fstream>
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int n,i,n1,n2,temp;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>n1>>n2;
        while(n2!=0)
        {
            temp=n1%n2;
            n1=n2;
            n2=temp;
        }
        g<<n1<<"\n";
    }
    return 0;
}
