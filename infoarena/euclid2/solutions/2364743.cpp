#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream cin("euclid2.in");
    ofstream cout("euclid2.out");
    int t,a,b,r;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>a>>b;
        if(a<b)
        {
            int tr=a;
            a=b;
            b=tr;
        }
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout<<a<<"\n";
    }
    return 0;
}
