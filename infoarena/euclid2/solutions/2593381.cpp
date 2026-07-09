#include <fstream>

using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int n,x,y;
int euclid(int x,int y)
{
    if(!y)
        return x;
    return euclid(y,x%y);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        cout<<euclid(x,y)<<endl;
    }
    return 0;
}
