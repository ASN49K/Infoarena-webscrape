//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int a,b;
int t,i;

int euclid(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<"\n";
    }
    return 0;
}
