#include <fstream>

using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int main()
{
    int n,x,y,i,r;
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>x>>y;
        while (y!=0)
        {
            r=x%y;
            x=y;
            y=r;
        }cout<<x<<"\n";

    }
    return 0;
}
