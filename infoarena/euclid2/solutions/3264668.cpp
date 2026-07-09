#include <fstream>

using namespace std;

ifstream cin("euclid2.in");
ofstream cout("euclid2.out");


int euclid(int a, int b)
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
    ios::sync_with_stdio(false);
    
    int t, a, b;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>a>>b;
        cout<<euclid(a, b)<<"\n";
    }
}