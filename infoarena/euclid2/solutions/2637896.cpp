#include <fstream>
using namespace std;
int euclid(int a,int b)
{
    if(a==0 && b!=0)
    {
        return b;
    }
    else
    if(b==0 && a!=0)
    {
        return a;
    }
    else
    {
        int rest;
        if(a<b)
        {
            swap(a,b);
        }
        while(a%b)
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        return b;
    }
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int t;
    int a,b;
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
    return 0;
}
