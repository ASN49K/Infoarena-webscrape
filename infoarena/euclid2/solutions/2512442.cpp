#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");

int t,a,b;

int cmmdc(int a,int b)
{
    while(b)
    {
        int rest=a%b;
        a=b;
        b=rest;
    }

    return a;
}

int main()
{
    cin>>t;

    while(t--)
    {
        cin>>a>>b;

        cout<<cmmdc(a,b)<<'\n';
    }

    return 0;
}
