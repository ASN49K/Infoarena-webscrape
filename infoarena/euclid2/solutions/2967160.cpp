#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int euclid(int x,int y)
{
    int r=x%y;
    while(r)
    {
        x=y;
        y=r;
        r=x%y;
    }
    return y;
}
int main()
{
    int t,x,y;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>x>>y;
        cout<<euclid(x,y)<<"\n";
    }
    return 0;
}
