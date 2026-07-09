#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=b;
        b=a%b;
        a=r;
    }
    return a;
}
int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<euclid(a,b)<<endl;
    }
    return 0;
}
