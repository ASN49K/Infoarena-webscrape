//#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a,b,c,n,i;
int main()
{
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a>>b;
        while(a!=b)
        {
            a=abs(a-b);
            b=abs(b-a);
        }
        cout<<a<<"\n";

    }
    return 0;
}
